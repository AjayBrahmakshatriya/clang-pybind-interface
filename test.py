import clang

args = ["clang"] + "-cc1 -triple x86_64-unknown-linux-gnu -emit-obj -disable-free -main-file-name hello.c -mrelocation-model static -mthread-model posix -mllvm -pass-remarks= -mllvm -pass-remarks-missed= -mllvm -pass-remarks-analysis= -fmath-errno -masm-verbose -mconstructor-aliases -munwind-tables -fuse-init-array -target-cpu x86-64 -dwarf-column-info -debugger-tuning=gdb -momit-leaf-frame-pointer -v -coverage-notes-file /afs/csail.mit.edu/u/a/ajaybr/scratch/pybind/clang_so/hello.gcno -resource-dir /data/scratch/ajaybr/llvm-learnt/build/lib/clang/6.0.1 -I/data/scratch/charithm/libraries/install/gcc-5.4/include -I/data/scratch/charithm/libraries/install/gcc-5.4/include -I. -internal-isystem /usr/local/include -internal-isystem /data/scratch/ajaybr/llvm-learnt/build/lib/clang/6.0.1/include -internal-externc-isystem /usr/include/x86_64-linux-gnu -internal-externc-isystem /include -internal-externc-isystem /usr/include -O3 -fdebug-compilation-dir /afs/csail.mit.edu/u/a/ajaybr/scratch/pybind/clang_so -ferror-limit 19 -fmessage-length 181 -fobjc-runtime=gcc -fdiagnostics-show-option -fcolor-diagnostics -vectorize-loops -vectorize-slp -mllvm --debug-pass=Arguments -o hello.o -x c hello.c -disable-free ".split()


clang.compile(len(args), args)
print (clang.get_function_count())
