inodetest
=========

```
Usage: inodetest NROOT_DIRS NDIRS NFILES [NDEL]
```

Implementation of a simple program that creates NROOT_DIRS * NDIRS * NFILES
inodes in the current working directory. It creates NROOT_DIRS root directories,
which contain NDIRS normal directories, which in turn contain NFILES files each.
The optional parameter NDEL contains the number of direcotries that should
be deleted.
