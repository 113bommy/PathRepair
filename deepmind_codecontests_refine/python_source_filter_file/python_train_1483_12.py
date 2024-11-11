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
    A();

def xdfs(root, v, sub, parent):
    st = [root];
    while len(st) > 0:
        node = st.pop();
        for i in range(len(v[node])):
            if v[node][i] != node:
                st.append(v[node][i]);


def X():
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

def bfs(v,root):
    q = [root,None];
    l = 0;
    visited = [0 for i in range(len(v))];
    dist = [0 for i in range(len(v))];
    while len(q) > 0:
        node = q.pop(0);
        if node is not None:
            visited[node] = 1;
            dist[node] = l;
            for i in range(len(v[node])):
                if visited[v[node][i]] == 0:
                    visited[v[node][i]] = 1;
                    q.append(v[node][i]);
        else:
            l += 1;
            if len(q) != 0:
                q.append(None);
    return dist;


def B():
    n = pi();
    v = [[] for i in range(n)];
    for i in range(n-1):
        [x,y] = ti();
        v[x-1].append(y-1);
        v[y-1].append(x-1);
    leafs = [];
    for i in range(n):
        if len(v[i]) == 1:
            leafs.append(i);

    mn = 1;
    d = bfs(v,leafs[0]);
    for i in range(1,len(leafs)):
        if d[leafs[i]] % 2 != 0:
            mn = 3;
            break;
    count = 0;
    for i in range(n):
        f = 0;
        for j in range(len(v[i])):
            if len(v[v[i][j]]) == 1:
                f = 1;
                break;
        if f: count += 1;
    mx = n-1-len(leafs)+count;
    print(mn,mx)


def A():
    [n,m] = ti();
    l = ti();
    res = [];
    s = 0;
    for i in range(m):
        s += l[i];
    pre = [0 for i in range(m)];
    for i in range(m):
        if i != 0: pre[i] = pre[i-1]+l[i];
        else: pre[i] = l[i];
    if s == n:
        for i in range(m):
            if i == 0: res.append(i+1);
            else: res.append(pre[i-1]+1);
        print(*res, sep=" ");
        return;
    if s < n:
        print(-1);
        return;
    if s > n:
        d = s-n;
        for i in range(m):
            if n-l[i] < i:
                print(-1);
                return;
            if i != m-1:
                res.append(i+1);
            else:
                res.append(i+d);
        print(*res, sep=" ");
                


main();