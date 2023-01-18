{ pkgs }: {
    deps = [
        pkgs.gnat.out
        pkgs.valgrind-light.out
	pkgs.clang_12
	pkgs.ccls
	pkgs.gdb
	pkgs.gnumake
    ];
}
