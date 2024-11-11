# -*- coding: utf-8 -*-
"""
Created on Tue Apr 28 22:56:10 2020
"""

import sys
#import numpy as np

sys.setrecursionlimit(10 ** 9)
#def input():
#    return sys.stdin.readline()[:-1]
mod = 10**9+7

N = int(input())
#X, Y = map(int,input().split())
ab = [list(map(int,input().split())) for i in range(N-1)]

fact = [1, 1] # 元テーブル
fact_inv = [1, 1] # 逆元テーブル
tmp_inv = [0, 1] # 逆元テーブル計算用テーブル
for i in range(2, N+1):
    fact.append((fact[-1] * i) % mod)
    tmp_inv.append((-tmp_inv[mod % i] * (mod//i)) % mod)
    fact_inv.append((fact_inv[-1] * tmp_inv[-1]) % mod)
def cmb(n, r, mod):
    if (r < 0 or r > n):
        return 0
    r = min(r, n-r)
    return fact[n] * fact_inv[r] * fact_inv[n-r] % mod
#逆元作成
def inv(a,mod):
    return pow(a,mod-2,mod)

graph = [[] for _ in range(N+1)]
for a, b in ab:
    graph[a].append(b)
    graph[b].append(a)

dp = [1] * (N + 1)
size = [0] * (N + 1)
def dfs(par, v):
    for u in graph[v]:
        if par == u:
            continue
        dfs(v, u)
        size[v] += size[u]
        dp[v] = dp[v] * dp[u] * fact_inv[size[u]] % mod
    dp[v] = dp[v] * fact[size[v]] % mod
    size[v] += 1

ans = [0] * (N + 1)
def reroot(par, val_par, size_par, v):
    ans[v] = val_par * dp[v] * cmb(N-1, size_par, mod) % mod
    for u in graph[v]:
        if par == u:
            continue
        val = ans[v] * inv(dp[u] * cmb(N-1, size[u],mod),mod) % mod
        reroot(v, val, N - size[u], u)

dfs(-1,1)
reroot(-1,1,0,1)
for i in range(1,N+1):
    print(ans[i])