import sys
def input(): return sys.stdin.readline().strip()
def mapint(): return map(int, input().split())
sys.setrecursionlimit(10**9)

N = int(input())
As = list(mapint())
As.sort()
mini = As.pop(0)
maxi = As.pop()

ans = []
for a in As:
    if a>=0:
        ans.append((mini, a))
        mini -= a
    else:
        ans.append(print(maxi, a))
        maxi -= a

print(maxi-mini)
for a in ans:
    print(*a)
    print(maxi, mini)