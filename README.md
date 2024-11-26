# KMP 文本查找与统计工具

此工具基于 **C++** 实现，结合 **KMP 算法**，可以快速查找文本文件中指定单词的位置及出现次数。程序会逐行读取文本内容，并统计指定单词在每一行的出现次数及总计。

## 功能说明

1. **支持多个单词查找**
   - 用户可以输入多个单词，程序会分别统计每个单词的出现位置及次数。

2. **基于 KMP 算法**
   - 通过高效的 KMP 算法查找指定单词，避免暴力查找带来的性能问题。

3. **文件动态读取**
   - 用户可自由选择读取的文本文件，若文件路径错误可重新输入。

4. **详细统计结果**
   - 显示每个单词在每一行的出现次数及总次数。

## 使用方法

### 1. 编译与运行
使用以下命令编译和运行程序：
```bash
g++ -o kmp_tool kmp_tool.cpp
./kmp_tool