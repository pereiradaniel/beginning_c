{ pkgs }: {
    deps = [
        pkgs.gnat.out
        pkgs.valgrind-light.out
    ];
}