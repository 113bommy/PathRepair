import sys
sys.setrecursionlimit(10**5)

n = int(input())
dic = {}
for i in range(n+1):
    if i <= 1: continue
    ai = int(input())
    if ai in dic:
        dic[ai].append(i)
    else:
        dic[ai] = [i]

def dfs(nxt):
    lst = []
    if nxt in dic:
        while dic[nxt] != []:
            child = dic[nxt].pop()
            tempmax = dfs(child)
            lst.append(tempmax)
    else:
        return 0
    lst.sort(reverse=True)
    for i in range(len(lst)):
        lst[i] += i+1
    return max(lst)

ans = dfs(1)
print(ans)