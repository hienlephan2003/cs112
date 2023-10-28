#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValid(string s)
{
    if (s.size() > 3)
    { // Độ dài tối đa của một phần là 3
        return false;
    }
    if (s.size() > 1 && s[0] == '0')
    { // Không được có số 0 ở đầu một phần có độ dài > 1
        return false;
    }
    int val = stoi(s); // Chuyển đổi chuỗi thành số nguyên
    if (val < 0 || val > 255)
    { // Giá trị của một phần phải trong khoảng từ 0 đến 255
        return false;
    }
    return true;
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> res; // Danh sách kết quả
    for (int i = 1; i < 4 && i < s.size() - 2; i++)
    { // Phần đầu tiên có độ dài tối đa là 3, và phải để lại đủ 3 phần
        for (int j = i + 1; j < i + 4 && j < s.size() - 1; j++)
        { // Phần thứ hai có độ dài tối đa là 3, và phải để lại đủ 2 phần
            for (int k = j + 1; k < j + 4 && k < s.size(); k++)
            {                                   // Phần thứ ba có độ dài tối đa là 3, và phải để lại đủ 1 phần
                string s1 = s.substr(0, i);     // Phần đầu tiên
                string s2 = s.substr(i, j - i); // Phần thứ hai
                string s3 = s.substr(j, k - j); // Phần thứ ba
                string s4 = s.substr(k);        // Phần thứ tư
                if (isValid(s1) && isValid(s2) && isValid(s3) && isValid(s4))
                {                                                       // Nếu địa chỉ IP hợp lệ
                    res.push_back(s1 + "." + s2 + "." + s3 + "." + s4); // Ghép các phần thành một địa chỉ IP và thêm vào danh sách kết quả
                }
            }
        }
    }
    return res;
}

int main()
{
    string s = "25525511135";
    vector<string> ips = restoreIpAddresses(s);
    for (string ip : ips)
    {
        cout << ip << endl;
    }
    return 0;
}