# Version Controller Plugin for Vim

A powerful Vim plugin that enhances your editing experience with advanced features such as a clipboard history manager, atomic-level version control, and buffer-independent operations.

## Features

- Clipboard history manager: Keep track of your copied texts and easily access them with the `sm` shortcut.
- Atomic-level version control: Save your changes as separate versions with the `sf` shortcut, allowing you to revert to previous versions easily.
- Buffer-independent operations: Perform operations across different buffers without switching between them.

![f6deea3d-e060-4668-91dd-a9a8154ee673](https://github.com/Git-Signs/Ropes/assets/65607123/8d95c04b-788b-4496-b88a-2f600dc13232)

## Requirements

Before running the plugin, make sure you have the following requirements installed:

- [Neovim](https://neovim.io/)
- Python 3

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/version-controller-vim-plugin.git
    ```

2. Navigate to the plugin's directory
    ```bash
    cd Vim-Controller
    ```
3. Install the required dependencies
    ```bash
    pip install -r requirements.txt
    ```

4. Add this line at the end of your .bashrc or .zshrc
    ```bash 
    alias nvim="NVIM_LISTEN_ADDRESS=/tmp/nvim nvim"
    ```


## Running the Plugin 

1. Run the Server file 
    ```bash 
    python3 final_nvim.py
    ```
2. Run Any instance of Neovim 
    ```bash nvim filename```


## Shortcuts

The following shortcuts are available for the plugin:

- `sm`: Display the contents of the copy buffer.
- `st`: Display the version history.
- `sf`: Save the current version.
- `tt`: Concatenate the last two entries of the copy buffer.
- `:w`: Save the file.

## Project Preview
![1](https://github.com/Git-Signs/Ropes/assets/79782433/c8db0fb3-1a42-4930-83c3-bd80780d9f48)
<br>
![2](https://github.com/Git-Signs/Ropes/assets/79782433/94d3fd0a-16f7-43c8-88e4-d2620b2385a9)


