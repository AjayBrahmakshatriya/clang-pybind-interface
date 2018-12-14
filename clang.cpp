#include <pybind11/pybind11.h>
#include <pybind11/stl.h>
#include <dlfcn.h>
#include <errno.h>
#include <signal.h>


typedef int (*main_type)(int argc, const char* argv[]);
extern "C" typedef int (*get_function_count_type)(void);

void *handle = NULL;

int compile(int argc, std::vector<std::string> argv) {
//int main(int argc, char *argv[]) {

	handle = dlopen("libclang_so.so", RTLD_DEEPBIND | RTLD_LAZY);
	if(!handle) {
		printf("Cannot find clang so errno = %d\n", errno);
		return -1;
	}
	main_type main = (main_type)dlsym(handle, "main");
	printf("Function =%p\n", (void*)main);

	const char **_argv = new const char*[argc];
	for(int i = 0 ; i < argc; i++){
		_argv[i] = strdup(argv[i].c_str());
		//printf("%s\n", _argv[i]);
	}
	//_argv[0]="clang";
	//_argv[1]="hello.c";
	int ret = main(argc, _argv);
	//int ret = 0;
	//dlclose(handle);	

	return ret;
}
int get_function_count(void) {
	if(!handle)
		return -1;
	get_function_count_type get_function_count_fn = (get_function_count_type)dlsym(handle, "get_function_count");
        if (!get_function_count_fn) {
		printf("get_function_count function not found\n");
		return -1;
	}
	return get_function_count_fn();
}
PYBIND11_MODULE(clang, m) {
    m.doc() = "pybind11 clang plugin"; // optional module docstring
    m.def("compile", &compile, "A function that invokes clang");
    m.def("get_function_count", &get_function_count, "A function that gets number of functions for the currently cached module");
}

