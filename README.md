# Version Controller Plugin for Vim

A powerful Vim plugin that enhances your editing experience with advanced features such as a clipboard history manager, atomic-level version control, and buffer-independent operations.

## Features

- Clipboard history manager: Keep track of your copied texts and easily access them with the `sm` shortcut.
- Atomic-level version control: Save your changes as separate versions with the `sf` shortcut, allowing you to revert to previous versions easily.
- Buffer-independent operations: Perform operations across different buffers without switching between them.

## Requirements

Before running the plugin, make sure you have the following requirements installed:

- [Neovim](https://neovim.io/)
- Python 3

## Installation

1. Clone the repository:

   ```bash
   git clone https://github.com/your-username/version-controller-vim-plugin.git
    ```

2. Change to the plugin's directory
    ```bash
    cd Vim-Controller
    ```
3. Install the required dependencies
    ```bash
    pip install -r requirements.txt
    ```

## Running the Plugin 


## Shortcuts

The following shortcuts are available for the plugin:

- `sm`: Display the contents of the copy buffer.
- `st`: Display the version history.
- `sf`: Save the current version.
- `tt`: Concatenate the last two entries of the copy buffer.
- `:w`: Save the file.

