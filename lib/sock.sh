#!/bin/bash
grep "alias nvim='NVIM_LISTEN_ADDRESS=/tmp/nvim nvim'" ~/.bashrc || echo "alias nvim='NVIM_LISTEN_ADDRESS=/tmp/nvim nvim'" >> "$HOME/.bashrc" 
