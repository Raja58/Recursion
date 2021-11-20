// <!--
//  ============================
//  @Author  :        raja_5
//  @Version :        1.0
//  @Date    :        20 Nov 2021
//  @Detail  :        Decode String (LeetCode)
//  ============================
//  -->

class Solution {
public:
  
    string decodeString(string str) {
        string result = "";
        for(int i = 0; i < str.size(); i++)
        {
            if(isalpha(str[i]))
                result = result + str[i];
            else
            {
                int j = i;
                while(j < str.size() && isdigit(str[j]))
                    j++;
                int cnt = stoi(str.substr(i, j - i));
                int endIdx = j, open = 0;
                do{
                    if(str[endIdx] == '[')
                        open++;
                    else if(str[endIdx] == ']')
                        open--;
                    endIdx++;
                }while(open != 0);
                string temp = str.substr(j + 1, endIdx - j - 2);
                temp = decodeString(temp);
                for(int k = 0; k < cnt; k++)
                    result = result + temp;
                i = endIdx - 1;
            }
        }
        return result;
    }
};
