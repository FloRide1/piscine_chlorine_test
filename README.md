# Piscine_chlorine_test

## Install 
If you want to add this project make: (NOT in your piscine folder)
```sh
git clone git@github.com:FloRide1/piscine_chlorine_test.git
```

Add in your `.gitignore`
```
# Remove chlorine test
*_test.c
```

Edit theses variable in `create_directory.sh`
```sh
NAME="<your_name>"
PISCINE_FOLDER="$HOME/afs/<your_piscine_path>"
SCRIPT_PATH="$HOME/afs/<your_chlorine_path>"
```

If you want to use the clang-format (`make format`), you need to
have it install (not by default on PIE)

### Please respect the format
This is just a student base project for making test faster

### Coding Style
The coding style is not mandatory on this project ;)

## Rules:
- Test MUST be in a folder name exactly like the project folder
- Tests MUST be name respecting this regex: `*_test.c`
- Tests MUST be true (LOL)
- You SHOULD modify your and only your test files
- The Rule above is not applied if a test is false: (Talk to the author before)
- Everytime you end a project you SHOULD push / pull your repo

### How to use it:
For Creating the new folder: (You should do it everytime your create a projet)
```sh
./create_directory <folder_name> (OPTIONNAL:<file_name>)
```

For Updating test:
```sh
./create_directory.sh
```

### Help:
If you can't push it's maybe because of a commit conflict:

If you have already commit:
```sh
git checkout .
```

If you have only change (before pull):
```sh
git stash
```
