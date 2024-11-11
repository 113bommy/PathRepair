import math as mt
import sys, string
from collections import Counter, defaultdict
input = sys.stdin.readline

# input functions
I = lambda : int(input())
M = lambda : map(int, input().split())
ARR = lambda: list(map(int, input().split()))

def printARR(arr):
    for e in arr:
        print(e, end=" ")
    print()

ans = 0
def dfs(u, graph, visited, curr_len, req_len):
    global ans
    if visited[u]:
        return
    visited[u] = 1
    if curr_len == req_len:
        ans += 1
        visited[u] = 0
        return
    for kid in graph[u]:
        dfs(kid, graph, visited, curr_len+1, req_len)
    visited[u] = 0

def main():
    v = {'a', 'e', 'i', 'o', 'u'}
    s = input()
    n = len(s) - 1
    i = 0
    while i < n:
        if s[i] == 'n':
            i += 2
            continue
        if s[i] not in v and i + 1 < n and s[i + 1] not in v:
            print("NO")
            return
        if s[i] not in v and i + 1 >= n:
            print("NO")
            return
        i += 1
    print("YES")

tc = 1
# tc = I()
for _ in range(tc):
    main()