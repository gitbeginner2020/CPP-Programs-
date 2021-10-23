 #include <bits/stdc++.h>
    #include <cstdio>
    #include <cstring>
    #include <cmath>
    #include <cstring>
    #include <chrono>
    #include <complex>
    #define endl "\n"
    #define ll long long int
    #define vi vector<int>
    #define vll vector<ll>
    #define vvi vector < vi >
    #define pii pair<int,int>
    #define pll pair<long long, long long>
    #define mod 1000000007
    #define inf 1000000000000000001;
    #define all(c) c.begin(),c.end()
    #define mp(x,y) make_pair(x,y)
    #define mem(a,val) memset(a,val,sizeof(a))
    #define eb emplace_back
    #define f first
    #define s second
    
    using namespace std;
    int main()
    {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

        int n;


        cin>>n;


        int a[n];

        int sum=0;

        for(int i=0;i<n;i++) {
            cin>>a[i];

            sum+=a[i];
        }


        int dp[n+1][sum+1];

        for(int j=0;j<sum+1;j++) {
            dp[0][j]=0;
        }

        for(int i=0;i<n+1;i++) {
            dp[i][0]=1;
        }


        set<int> s;

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=sum;j++) {
                if(a[i-1]<=j) {
                    dp[i][j] = dp[i-1][j-a[i-1]]||dp[i-1][j];
                    if(dp[i][j]==1) {
                        s.insert(j);
                    }
                }

                else {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }


        cout<<s.size()<<endl;

        for(auto x:s) {
            cout<<x<<" ";
        }






        return 0;
    }
