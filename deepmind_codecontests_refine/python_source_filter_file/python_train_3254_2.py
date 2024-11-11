import sys
import math
input = sys.stdin.readline
from functools import cmp_to_key;

def pi():
    return(int(input()))
def pl():
    return(int(input(), 16))
def ti():
    return(list(map(int,input().split())))
def ts():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))
mod = 1000000007;
f = [];
def fact(n,m):
    global f;
    f = [1 for i in range(n+1)];
    f[0] = 1;
    for i in range(1,n+1):
        f[i] = (f[i-1]*i)%m;

def fast_mod_exp(a,b,m):
    res = 1;
    while b > 0:
        if b & 1:
            res = (res*a)%m;
        a = (a*a)%m;
        b = b >> 1;
    return res;

def inverseMod(n,m):
    return fast_mod_exp(n,m-2,m);

def ncr(n,r,m):
    if r == 0: return 1;
    return ((f[n]*inverseMod(f[n-r],m))%m*inverseMod(f[r],m))%m;

def main():
    B();

def dfs(root, v, sub, parent):
    st = [root];
    while len(st) > 0:
        node = st.pop();
        for i in range(len(v[node])):
            if v[node][i] != node:
                st.append(v[node][i]);


def D():
    try:
        t = pi();
        while t:
            t -= 1;
            n = pi();
            v = [[] for i in range(n)];
            for i in range(n-1):
                [x,y] = ti();
                v[x-1].append(y-1);
                v[y-1].append(x-1);
            m = pi();
            p = ti();
            e = [0 for i in range(n-1)];
            sub = [0 for i in range(n)];
            dfs(0,v,sub,-1)
            for i in range(1,n):
                e[i-1] = (sub[i]*(n-sub[i]));
            if len(p) < n-1:
                while len(p) < n-1:
                    p.append(1);
            p = sorted(p);    
            if len(p) > n-1:
                x = 1;
                for i in range(n-2,len(p)):
                    x = (x*p[i]);
                while len(p) > n-2:
                    p.pop();
                p.append(x);

            e = sorted(e);
            res = 0;
            for i in range(n-1):
                res = (res+(p[i]*e[i]))%mod;
            print(res);
    except:
        print(sys.exc_info());

def B():
    t = pi();
    while t:
        t -= 1;
        n,a = pi(),ti();
        idx = [0 for i in range(2*n+1)];
        for i in range(2*n):
            idx[a[i]] = i;
        p = 2*n-1;
        s = [];
        for i in range(2*n,-1,-1):
            if idx[i] <= p:
                s.append(p-idx[i]+1);
                p = idx[i]-1;
        
        dp = [[0 for j in range(len(s)+1)] for i in range(n+1)];
        dp[0][0] = 1;
        for i in range(1,n+1):
            for j in range(1,len(s)+1):
                if i-s[j-1] >= 0:
                    dp[i][j] = 1 if dp[i][j-1] or dp[i-s[j-1]][j-1] else 0;
                else:
                    dp[i][j] = dp[i][j-1];

        print(dp);
        print(s);
        print("YES" if dp[n][len(s)] == 1 else "NO");


main();