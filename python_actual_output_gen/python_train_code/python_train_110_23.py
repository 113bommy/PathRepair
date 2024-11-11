import sys
r = lambda: sys.stdin.readline()
n, x, y = map(int,r().split())
answer = 0
end = str(10**x+10**y)
nn = input()
nn = nn[-x-1:]


for i in range(x+1):
    if nn[i] != end[i]:
        answer+=1


print(answer)
