//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n=s.size(), l=0, r=0, ans=-1;
        map<char, int> cnt;
        
        while(r<n) {
            cnt[s[r]]++;
            if(cnt.size()==k) {
                ans = max(ans, r-l+1);
            }
            else {
                while(cnt.size()>k && l<=r) {
                    cnt[s[l]]--;
                    if(cnt[s[l]]==0) {
                        cnt.erase(s[l]);
                    }
                    l++;
                }
            }
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends