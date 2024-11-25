#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

// 函数：生成部分匹配表（KMP算法中的pi表）
vector<int> kmp_table(const string& pattern) {
    vector<int> pi(pattern.size(), 0);
    int j = 0;
    for (int i = 1; i < pattern.size(); i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
            pi[i] = j;
        }
    }
    return pi;
}

// 函数：KMP算法
vector<int> kmp_search(const string& text, const string& pattern) {
    vector<int> pi = kmp_table(pattern);
    vector<int> positions;
    int j = 0;
    for (int i = 0; i < text.length(); i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = pi[j - 1];
        }
        if (text[i] == pattern[j]) {
            if (j == pattern.size() - 1) {
                positions.push_back(i - j);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return positions;
}

int main() {
    ifstream file;
    string filename = "KMP666.txt";
    while (true) {
        file.open(filename);
        if (file.is_open()) {
            break;
        }
        cerr << "Failed to open file: " << filename << endl;
        cout << "Enter a valid filename or type 'exit' to quit: ";
        getline(cin, filename);
        if (filename == "exit") {
            return 1;
        }
    }

    string line;
    vector<string> lines;
    map<string, map<int, int>> word_counts;

    // 读取文件的每一行到vector中
    while (getline(file, line)) {
        lines.push_back(line);
    }
    file.close();

    // 获取待查找的单词
    cout << "Enter words separated by spaces: ";
    string input;
    getline(cin, input);
    stringstream ss(input);
    vector<string> words;
    string word;
    while (ss >> word) {
        words.push_back(word);
        word_counts[word] = {};
    }

    // 对每一行使用KMP算法查找每个单词
    for (int i = 0; i < lines.size(); i++) {
        for (const auto& w : words) {
            vector<int> positions = kmp_search(lines[i], w);
            if (!positions.empty()) {
                word_counts[w][i + 1] = positions.size();
            }
        }
    }

    // 输出每个单词的统计结果
    for (const auto& wc : word_counts) {
        cout << "Word: " << wc.first << endl;
        cout << "Occurrences: ";
        int total_count = 0;
        for (const auto& line : wc.second) {
            total_count += line.second;
            cout << "Line " << line.first << " (" << line.second << " times), ";
        }
        cout << "Total: " << total_count << endl << endl;
    }
    cout << "Press any key to exit..." << endl;
    cin.get();
    return 0;
}
