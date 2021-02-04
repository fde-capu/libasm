# libasm

In a hurry, so messy README.md.

### Subject:

- Common instructions. Note that in this case the test program is also delivered. 
- Check and set errno on  syscalls, may use `extern ___error`.

### Makefile

`make` calls `make proof`: builds `libasm.a` and link to the (`.c`, `.h`) files, giving `proof.out`. If you only want the library you may use `make library`.

`proof.out` demonstrates the linkage by unit testing and verifying return values, `stdout` and `errno` agains the expected output from standard libraries.

### Functions covered:

```
	extern ssize_t	ft_write(int fd, const void *buf, size_t count);
	extern size_t	ft_strlen(const char *s);
	extern char		*ft_strcpy(char *dest, const char *src);
	extern int		ft_strcmp(const char *s1, const char *s2);
	extern ssize_t	ft_read(int fd, void *buf, size_t count);
	extern char		*ft_strdup(const char *s);
```

### To-do:

[ ] Set errno on all.
[ ] Exhaustive tests.
[ ] Test on VM.
[ ] Norme.

---

*this project is part of the 42 São Paulo cursus*

---

Copyright 2021 fde-capu

I enjoyed building this project but I doubt any experienced Assembly programmer would encounter anything out of the ordinary along the lines of code. So everyone is authorized to use this piece of software at their own risk, not without giving credit. Still, if you are a 42 student you are allowed to look and ponder, but to copy is strictly forbidden.
