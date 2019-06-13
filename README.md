# ft_ls

[![Build Status](https://travis-ci.org/hugohow/ft_ls.svg?branch=master)](https://travis-ci.org/hugohow/ft_ls)

`ft_ls -RulrSlg ~/` works perfectly and has exactly the same beahaviour than ls.

Implementation of balanced binary tree (avl tree) to get good performance on recursive call.

Consideration of all edge cases (different permission mode with ACL, setuid, setgid, dirty bit ; different type of file like symlink, pipe, character, ...)

## TO DO

Add `make test` for linux

## Usage

```
usage: ./ft_ls [-RGUSagilortu1] [file ...]
```

### OSX :

```
make re
./ft_ls
```

### Linux :

```
sudo apt-get install -y libc6-dev libacl1-dev
make re
./ft_ls
```

