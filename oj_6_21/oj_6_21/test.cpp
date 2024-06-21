#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//https://leetcode.cn/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        string str;
        for (int dest = 0; dest < s.size(); dest++)
        {
            for (int cur = dest; cur < s.size(); cur++)
            {
                int len_str = str.size();
                int left = dest, right = cur;
                int i = left, j = right;
                bool is_sub = true;
                while (left <= right)
                {
                    if (s[left] != s[right])
                    {
                        is_sub = false;
                        break;
                    }
                    left++, right--;
                }
                if (is_sub && len_str < j - i + 1) str = s.substr(i, j - i + 1);
            }
        }
        return str;
    }
};



//https://leetcode.cn/problems/3sum-closest/description/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = 0;
        int sub;
        for (int i = 0; i < nums.size() - 2; i++)
        {
            int left = i + 1, right = nums.size() - 1;
            if (i == 0) sub = abs(target - nums[left] - nums[right] - nums[i]);
            while (left < right)
            {
                if (nums[i] + nums[left] + nums[right] < target)
                {
                    if (i == 0 && left == i + 1 && right == nums.size() - 1)
                    {
                        ret = nums[i] + nums[left] + nums[right];
                    }
                    else
                    {
                        if (abs(target - (nums[i] + nums[left] + nums[right])) < sub)
                        {
                            ret = nums[i] + nums[left] + nums[right];
                            sub = abs(target - nums[left] - nums[right] - nums[i]);
                        }
                    }
                    left++;
                }
                else
                {
                    if (i == 0 && left == i + 1 && right == nums.size() - 1)
                    {
                        ret = nums[i] + nums[left] + nums[right];
                    }
                    else
                    {
                        if (abs(target - (nums[i] + nums[left] + nums[right])) < sub)
                        {
                            ret = nums[i] + nums[left] + nums[right];
                            sub = abs(target - nums[left] - nums[right] - nums[i]);
                        }
                    }
                    right--;
                }
            }
        }
        return ret;
    }
};


//https://leetcode.cn/problems/remove-nth-node-from-end-of-list/description/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head, * fast = head;
        while (n--) fast = fast->next;

        while (fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == nullptr)
        {
            head = head->next;
        }
        else
        {
            slow->next = slow->next->next;
        }

        return head;
    }
};



//https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
class Solution {
public:
    int strStr(string haystack, string needle) {
        int dest = 0, cur = 0;
        while (dest < haystack.size())
        {
            int pos = 0;
            while (pos < needle.size())
            {
                if (haystack[cur] == needle[pos])
                {
                    cur++, pos++;
                }
                else
                {
                    break;
                }
            }
            if (pos == needle.size()) return dest;

            dest++;
            while (dest < haystack.size() && haystack[dest] != needle[0]) dest++;
            cur = dest;
        }
        return -1;
    }
};



//https://leetcode.cn/problems/next-permutation/description/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int dest = nums.size() - 1;
        int cur = dest;
        bool t = true;
        while (dest > 0)
        {
            if (nums[dest - 1] < nums[dest])
            {
                t = false;
                dest = dest - 1;
                break;
            }
            dest--;
        }
        while (cur > 0)
        {
            if (nums[cur] > nums[dest])
            {
                break;
            }
            cur--;
        }

        swap(nums[dest], nums[cur]);
        if (!t)
        {
            int i = dest + 1, j = nums.size() - 1;
            while (i < j)
            {
                swap(nums[i], nums[j]);
                i++, j--;
            }
        }
        else
        {
            sort(nums.begin(), nums.end());
        }
    }
};