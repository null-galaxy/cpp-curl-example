// Example of using libcurl for HTTP GET and POST requests in C++
// This program demonstrates how to perform GET and POST requests using the 
// libcurl library. For more detailed information on using libcurl, visit the 
// official tutorial: https://curl.se/libcurl/c/libcurl-tutorial.html

#include <iostream>
#include <string>
#include <curl/curl.h>

/**
 * Callback function for writing received data to a string.
 * @param receivedData Buffer containing received data.
 * @param dataSize Size of each data block received.
 * @param dataBlocks Number of data blocks received.
 * @param outputBuffer Pointer to a string where the received data will be stored.
 * @return The total number of bytes taken care of. If this number differs from 
 * the number of bytes provided, it'll signal an error to the library.
 * 
 * The prototype for this callback function is described here:
 * https://curl.se/libcurl/c/CURLOPT_WRITEFUNCTION.html
 */
static size_t
WriteCallback(
    char *receivedData,
    size_t dataSize,
    size_t dataBlocks,
    void *outputBuffer
) {
    std::string *strBuffer = static_cast<std::string*>(outputBuffer);
    strBuffer->append(receivedData, dataSize * dataBlocks);
    return dataSize * dataBlocks;
}

/**
 * Performs an HTTP GET request.
 * @param requestUrl URL to which the GET request is made.
 */
void
performGetRequest(
    const std::string& requestUrl
) {
    CURL *curlHandle = curl_easy_init();
    if (curlHandle) {
        CURLcode result;
        std::string responseBuffer;

        curl_easy_setopt(curlHandle, CURLOPT_URL, requestUrl.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &responseBuffer);
        curl_easy_setopt(curlHandle, CURLOPT_HTTPGET, 1L);

        result = curl_easy_perform(curlHandle);
        if (result != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: "
                      << curl_easy_strerror(result) << std::endl;
        } else {
            std::cout << "GET Request Output: " << responseBuffer << std::endl;
        }

        curl_easy_cleanup(curlHandle);
    }
}

/**
 * Performs an HTTP POST request.
 * @param requestUrl URL to which the POST request is made.
 * @param postData Data to be sent in the POST request.
 */
void
performPostRequest(
    const std::string& requestUrl, 
    const std::string& postData
) {
    CURL *curlHandle = curl_easy_init();
    if (curlHandle) {
        CURLcode result;
        std::string responseBuffer;

        curl_easy_setopt(curlHandle, CURLOPT_URL, requestUrl.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_POSTFIELDS, postData.c_str());
        curl_easy_setopt(curlHandle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curlHandle, CURLOPT_WRITEDATA, &responseBuffer);
        curl_easy_setopt(curlHandle, CURLOPT_POST, 1L);

        result = curl_easy_perform(curlHandle);
        if (result != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: "
                      << curl_easy_strerror(result) << std::endl;
        } else {
            std::cout << "POST Request Output: " << responseBuffer << std::endl;
        }

        curl_easy_cleanup(curlHandle);
    }
}

int
main() {
    CURLcode globalInitResult = curl_global_init(CURL_GLOBAL_DEFAULT);
    if (globalInitResult != CURLE_OK) {
        std::cerr << "curl_global_init() failed: "
                  << curl_easy_strerror(globalInitResult) << std::endl;
        return 1;
    }

    std::string getUrl = "http://httpbin.org/get";
    std::string postUrl = "http://httpbin.org/post";
    std::string postData = "field1=value1&field2=value2";

    performGetRequest(getUrl);
    performPostRequest(postUrl, postData);

    curl_global_cleanup();

    return 0;
}
