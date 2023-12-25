# Linux-CShell

# Custom Unix System Shell

This project implements a custom Unix system shell with three specific commands: `word`, `dir`, and `date`. The shell is designed to be used in a C Shell environment and provides functionality as specified by the project guidelines.

## Commands

### 1. `word`

#### Syntax

```bash
word [-n | -d] [file_name]
```

- `word`: Built-in command to count words in a text file.
- Options:
  - `-n`: Ignores new line characters.
  - `-d`: Displays the difference between word sizes of two text files.
- `file_name`: The name of the text file.

#### Examples

```bash
# Count words in a file
word myfile.txt

# Count words excluding new line characters
word -n myfile.txt

# Display the difference between word sizes of two files
word -d file1.txt file2.txt
```

### 2. `dir`

#### Syntax

```bash
dir [-r | -v] [dir_name]
```

- `dir`: External command to create and change the path to a directory.
- Options:
  - `-r`: Removes the directory if it already exists and creates a new one.
  - `-v`: Prints a message for each step in the command execution.
- `dir_name`: The name of the directory.

#### Examples

```bash
# Create and change path to a directory
dir mydirectory

# Remove and recreate directory if it already exists
dir -r existing_directory

# Print messages for each step
dir -v another_directory
```

### 3. `date`

#### Syntax

```bash
date [-d | -R] [file_name]
```

- `date`: External command to return the last modified date and time of a file.
- Options:
  - `-d`: Displays time described by STRING.
  - `-R`: Outputs date and time in RFC 5322 format.
- `file_name`: The name of the file.

#### Examples

```bash
# Get last modified date and time of a file
date myfile.txt

# Display time described by a specific string
date -d "2023-01-01 12:00:00" myfile.txt

# Output date and time in RFC 5322 format
date -R another_file.txt
```

## Implementation Details

The project consists of three separate C programs: `main.c`, `dir.c`, and `date.c`. The `main.c` file is the core of the custom shell, while `dir.c` and `date.c` contain the implementations for the `dir` and `date` commands, respectively.

### Compilation

To compile the project, use the following commands:

```bash
gcc -o custom_shell main.c
gcc -o dir_command dir.c
gcc -o date_command date.c
```

### Running the Shell

```bash
./custom_shell
```

Enter commands as described in the syntax examples above.

**Note:** Ensure that the `dir_command` and `date_command` executables are in the same directory as the `custom_shell` executable.

## Contributors

- [Your Name]
- [Contributor 2 Name]

## License

This project is licensed under the [MIT License](LICENSE).

Feel free to contribute and improve this custom Unix system shell!
