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
    if n < 0 or r < 0 or r > n: return 0;
    if r == 0: return 1;
    return ((f[n]*inverseMod(f[n-r],m))%m*inverseMod(f[r],m))%m;

def main():
    C();

def D():
    [n,m,k] = ti();
    w = [[] for i in range(n)];
    for i in range(n):
        w[i] = ts();

    mn = [[0 for j in range(k+1)] for i in range(n+1)];
    for i in range(1,n+1):
        for j in range(k+1):
            c = 0;
            st,en = -1,-1;
            for x in range(m):
                if w[i-1][x] == '1':
                    if c == j and st == -1: st = x;
                    if c < j: c += 1;
                    if c == j: en = x;
            mn[i][j] = en-st+1 if st != -1 and en != -1 else 0;
            st,en = -1,-1;
            c = 0;
            for x in range(m-1,-1,-1):
                if w[i-1][x] == '1':
                    if c == j and st == -1: st = x;
                    if c < j: c += 1;
                    if c == j: en = x;
            if st != -1 and en != -1 >= 0:
                mn[i][j] = min(mn[i][j], st-en+1);

    dp = [[9999999999999999 for j in range(k+1)] for i in range(n+1)];
    for i in range(k+1):
        dp[0][i] = 0;
    for i in range(1,n+1):
        for j in range(k+1):
            for x in range(k+1):
                if j-x >= 0:
                    dp[i][j] = min(dp[i][j], dp[i-1][j-x]+mn[i][x]);

    print(dp[n][k]);

def getCount(n):
    x = 1;
    count = 0;
    while n > 0:
        if n & 1 == 1:
            count += 1;
        n = n >> 1;
    return count;

def C():
    try:
        n = ts();
        k = pi();
        if k == 0:
            print(1);
            return;
        dp = [0 for i in range(1000)];
        for i in range(1000):
            if i == 0 or i == 1:
                continue;
            dp[i] = dp[getCount(i)]+1;
        fact(1000,mod);

        ans = 0;    
        s = n;
        count = 0;
        for i in range(len(s)):
            if s[i] == '0': continue;
            for j in range(max(count,1),1000):
                if dp[j] == k-1:
                    ans = (ans+ncr(len(s)-i-1,j-count,mod))%mod;
                    if i == 0 and k == 1: ans = (ans+mod-1)%mod;
            count += 1;
        count = 0;
        for i in range(len(s)):
            if s[i] == '1': count += 1;
        if dp[count] == k-1: ans = (ans+1)%mod;

        print(ans);
    except: print(sys.exc_info()[0]);


main();