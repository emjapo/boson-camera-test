#include <thread>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include <fcntl.h>               // open, O_RDWR
#include <opencv2/opencv.hpp>
#include <unistd.h>              // close
#include <sys/ioctl.h>           // ioctl
#include <asm/types.h>           // videodev2.h
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <linux/videodev2.h>
#include <thread>
#include <vector>

/*
for testing purposes
*/


using namespace std;

void thread_start(int foo, int bar) {
    int result = foo + bar;
    cout << "This thread got " << result << endl;
}

int main() {

    char integer_string[32];
    int device = 2;
	char folder_name[30];  // To store the folder name


	sprintf(folder_name, "camera_capture_%i", device);

    char cwd[PATH_MAX];

    getcwd(cwd, sizeof(cwd));
   strcat(cwd, "/");
   strcat(cwd, folder_name);
	

    cout << "folder name is  " << cwd << endl;
    thread th1(thread_start, 5, 10);

    thread th2(thread_start, 7, 1);

    th1.join();

    th2.join();

    return 0;
}