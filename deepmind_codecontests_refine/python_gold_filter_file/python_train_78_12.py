import sys
sys.setrecursionlimit(10**7)
n = int(input())

def dfs(s):
    if len(s) == n:
        print(s)
    else:
        for x in map(chr, range(97, ord(max(s))+2)):
            dfs(s+x)


dfs("a")