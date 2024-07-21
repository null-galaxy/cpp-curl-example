# HTTP Request Examples in C++

This repository contains two examples demonstrating HTTP GET and POST 
requests using C++ and the libcurl library. The examples are structured 
to provide a simple and a more complex scenario.

Official libcurl website:\
\- https://curl.se/libcurl/

Useful Gist + conversation:\
\- https://gist.github.com/alghanmi/c5d7b761b2c9ab199157


## File Descriptions

1. **1_simplest_http_get.cpp**  
   This file contains the simplest example of making an HTTP GET request. 
   It's designed to show the basic use of libcurl for a GET request.

2. **2_http_get_post.cpp**  
   This file includes examples of both GET and POST requests, with each 
   request type implemented in separate functions for clarity and 
   modularity.

## 1. Dependency Installation

Before compiling and running the examples, you need to install the libcurl 
library:

### 1.1. Ubuntu

Install libcurl using the following command:

```console
$ sudo apt-get update
$ sudo apt-get install libcurl4-openssl-dev
```

### 1.2. Windows

For Windows, you can download the pre-built binaries and include them in
your project from the official libcurl website, or use vcpkg to install
libcurl:

```console
$ vcpkg install curl
```

Ensure that the path to the libcurl libraries is added to your system's PATH
environment variable.

## 2. Downloading the Repository

To download the repository, you have a few options

### 2.1. Clone the Repository via git and jump into dir

If you have Git installed on your system, you can clone the repository using\
the following command in your terminal or command prompt:

```console
  # Clone the repo via HTTPS (Do not use SSH because it requires configured credentials)
$ REPO_URL='https://github.com/null-galaxy/cpp-curl-example.git' &&\
  GOAL_DIR_NAME='cpp-curl-example' &&\
  git clone "${REPO_URL}" "${GOAL_DIR_NAME}" &&\
  cd "${GOAL_DIR_NAME}"
```
This will create a local copy of the repository on your machine.

### 2.2. Download as ZIP file

Alternatively, you can download the repository as a ZIP file.\
Simply navigate to the repository's page here and click on the "Code" button.\
Then select "Download ZIP" to save the ZIP file to your computer.\
After downloading, extract the contents of the ZIP file to access the repository files.

## 3. Compilation Instructions

### 3.1. Using CMake (Recommended)

A `CMakeLists.txt` is provided for easy compilation of the examples. To compile
both files, follow these steps:

```console
$ mkdir build &&\
  cd build &&\
  cmake .. &&\
  cmake --build .
```

To clean up compiled binaries, simply delete the build directory:

```console
$ cd ..
$ rm -rf build
```

### 3.2. Using Command Line

If you prefer to compile the files manually without a Makefile, use the 
following commands:

- For compiling the simplest GET example:

  ```console
  $ g++ -Wall -Wextra -O2 -std=c++11 -o 1_simplest_http_get 1_simplest_http_get.cpp -I/usr/include -lcurl
  ```

- For the more complex GET and POST example:

  ```console
  $ g++ -Wall -Wextra -O2 -std=c++11 -o 2_http_get_post 2_http_get_post.cpp -I/usr/include -lcurl
  ```

## 4. Running the Examples

After compilation, you can run the executables to see the HTTP requests in 
action:

- Run the simplest HTTP GET example:

  ```console
  $ ./1_simplest_http_get
  ```

  You should see the HTML content of "http://example.com" printed to the console.

- Run the GET and POST example:

  ```console
  $ ./2_http_get_post
  ```

  This will execute GET and POST requests, and you should see the responses 
  from the server displayed in the console.
