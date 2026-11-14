#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

bool writePimcDataToFile(vector<U32>& data, const std::string& fileName)
{
    std::ofstream file(fileName, std::ios::trunc);  // 创建一个ofstream对象，把文件打开并与之关联，文件模式为覆盖trunc
    if (file.is_open())  // 如果文件被打开了
    {
        std::copy(data.begin(), data.end() - 1, std::ostream_iterator<U32>(file, ","));  // 将vector中的第一个到倒数第二个保存到文件中
        file << data.back();  // 把最后一个元素保存到文件中
        file.close();  // 关闭文件
        RADIO_INFO("Raw data has been written to %s successfully.", fileName.c_str());
    }
    else
    {
        RADIO_ERROR("Unable to open the file:%s", fileName.c_str());
        return false;
    }
    return true;
}
