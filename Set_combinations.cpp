/*
Welcome to the exciting class of Professor Manasa. In each lecture she used to play some game while teaching a new concept. Today's topic is Set Theory. For today's game, she had given a set A = {a1, a2, ...aN} of N integers to her students and asked them to play the game as follows.

At each step of the game she calls a random student and asks him/her to select a non-empty subset from set A such that this subset had not been selected earlier and the sum of subset should be even. This game ends when all possible subsets had been selected. Manasa needs your help in counting the total number of times students can be called assuming each student gives the right answer. While it is given that if two numbers are same in the given set, they have different colors. It means that if a1 = a2, then choosing a1 and choosing a2 will be considered as different sets.

Note

Two subsets are different if there exists an element (ak) that is present in one subset but not in other. Let's say set A = {a1, a2, a3} = {2, 2, 3}, then all possible subsets are {}, {a1}, {a2}, {a3}, {a1, a2}, {a1, a3}, {a2, a3}, {a1, a2, a3} which is equivalent to {}, {2}, {2}, {3}, {2, 2}, {2, 3}, {2, 3}, {2, 2, 3}.

Students can be called multiple times.

Input Format
The first line contains an integer N i.e. size of set A.
Next line will contain N integers, each representing an element of A.

Output Format
Print number of time students are called. As this number can be very large you have to print the answer modulo (109 + 7).

Constraints
1 ≤ N ≤ 105
0 ≤ ai ≤ 104 , where i ∈ [1 .. N]

Sample Input 00

4
2 4 6 1
Sample Output 00

7
Sample Input 01

3
1 2 2
Sample Output 01

3
Explanation
There are 7 different ways in which a non-empty subset, with even sum, can be selected, i.e., {2}, {4}, {6}, {2, 4}, {2, 6}, {4, 6}, {2, 4, 6}.

For second sample test case, there are 3 different ways in which a non-empty subset, with even sum, can be selected, i.e., {a2}, {a3}, {a2, a3} which is equivalent to {2}, {2}, {2,2}.


Input (stdin)
4
2 4 6 1
Expected Output
7

*/


















#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1e9+7;
ll power(ll a,ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans *= a;
            ans %= mod;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return ans;
}
ll inverse(ll n,ll m){
    return power(n,m);
}
int main(){
    ll n;
    cin >> n;
    ll odd = 0;
    ll even = 0;
    vector<ll> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
        if(a[i]&1) odd++;
        else even++;
    }
    ll ans = 0;
    ll res = 0;
    ll ans2 = 0;
    if(even != 0){
        ans = (power(2,even))%mod;
        ans--;
    }
    if(odd!=0){
        res = (power(2,odd)%mod * inverse(2,mod-2)%mod)%mod;
        res--;
    }
    if(odd!=0 and even!=0) ans2 = (ans * res)%mod;
    ans = (ans + res + ans2)%mod;
    cout << (int)ans;
    
}
