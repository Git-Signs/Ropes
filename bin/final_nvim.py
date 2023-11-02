from pynvim import attach
import subprocess

import json 

def run_c_program(cmd, num, proc):
    input_str = f"{cmd}{num}"
    proc.stdin.write(input_str)
    proc.stdin.flush()

    output = proc.stdout.readline()
    return output.strip()



nvim = attach('socket', path='/tmp/nvim')

last_changedtick = None
processed_lines = dict()

yanked = ''
deleted = ''

current_buffer = nvim.current.buffer
changed_lines = current_buffer.api.get_lines(0, -1, True)

for line, data in enumerate(changed_lines):
    if line not in processed_lines:
        processed_lines[line] = data
        continue
    if processed_lines[line] != data:
        processed_lines[line] = data


nvim.subscribe('yanked')
nvim.subscribe('saved')
nvim.subscribe('addedline')
nvim.subscribe('rmedline')
nvim.subscribe('intobuffer')
nvim.subscribe('concatclip')
yanked_lines = []

cmd = """highlight CustomError ctermfg=red guifg=red"""
nvim.command(cmd)
cmd = "sign define error numhl=CustomError"
nvim.command(cmd)


cmd = """highlight CustomAdd ctermfg=green guifg=green"""
nvim.command(cmd)
cmd = "sign define addline numhl=CustomAdd"
nvim.command(cmd)

proc = subprocess.Popen(['./ropeclient'], stdin=subprocess.PIPE, stdout=subprocess.PIPE, universal_newlines=True)

po = proc.stdout.readline()

while True:
    sd = nvim.next_message()
    print(sd)

    if sd[1] == "rmedline":
        c = sd[2][0]
        a = f"sign place 1 name=error line={c}"
        nvim.command(a)
        print(sd)

    if sd[1] == "addedline":
        c = sd[2][0]
        a = f"sign place 1 name=addline line={c}"
        nvim.command(a)
        print(sd)

    if sd[1] == "concatclip":
        c = "1\n3"
        a = run_c_program(c, "\n", proc)
        nvim.command(f"let @+='{a}'")
        print(a)

    if sd[1] == "yanked":
        yanked_string = nvim.eval('@\"')
        command = "1\n1\n" 
        number = repr(sd[2][-1])[1:-1]+"\n"
        y = run_c_program(command, number, proc)
        print("THIS GOT YANKED:", y)
        yanked = yanked_string
        deleted = ''  # Reset the deleted content
        

    if sd[1] == 'saved':
        buffer = nvim.current.buffer
        changedtick = buffer.api.get_changedtick()
        if (
            buffer == current_buffer
            and changedtick != last_changedtick
        ):
            last_changedtick = changedtick
            changed_lines = buffer.api.get_lines(0, -1, True)

            s = ['notification', 'saved', [1, '/root/final_dsa/rope.c']]

            for line, data in enumerate(changed_lines):
                cmd = "0\n"
                if line not in processed_lines:
                    processed_lines[line] = data
                    print(line)
                if processed_lines[line] != data:
                    processed_lines[line] = data
                    print(line)

    nvim.command('sleep 10m')

'''

proc.stdin.close()
proc.wait()



        cds = "{"+json.dumps(y)[1:-1]+"}"
        a = """local actions = require "telescope.actions"
            local action_state = require "telescope.actions.state"
            local pickers = require "telescope.pickers"
            local finders = require "telescope.finders"
            local sorters = require "telescope.sorters"
            
            function enter(prompt_buffer)
                local selected = action_state.get_selected_entry()
                local cmd = "call rpcnotify(0,'intobuffer','"..selected[1] .."')"
                vim.cmd(cmd)
                local cmd1 = "let @+='"..selected[1].."'"
                vim.cmd(cmd1)
                actions.close(prompt_buffer)
            end

            local opts = { layout_strategy = "vertical", finder = finders.new_table"""+cds+""", sorter = sorters.get_generic_fuzzy_sorter({}), attach_mappings = function(prompt_buffer, map)
                map("i", "<CR>", enter)
                map("n", "<CR>", enter)
                return true 
            end,
            }
            local lel = pickers.new(opts)
            lel:find()"""
        nvim.command("lua "+a)


'''
