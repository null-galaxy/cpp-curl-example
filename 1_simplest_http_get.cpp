#include <curl/curl.h>
#include <iostream>

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

int
main() {
  curl_global_init(CURL_GLOBAL_DEFAULT);
  CURL *curl = curl_easy_init();
  std::string readBuffer;
  
  if (curl) {
    curl_easy_setopt(curl, CURLOPT_URL, "http://example.com");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
    CURLcode res = curl_easy_perform(curl);
    
    if (res != CURLE_OK)
      std::cerr << "Error: " << curl_easy_strerror(res) << std::endl;
    
    curl_easy_cleanup(curl);
  }

  curl_global_cleanup();
  std::cout << "Data: " << readBuffer << std::endl;
  return 0;
}
