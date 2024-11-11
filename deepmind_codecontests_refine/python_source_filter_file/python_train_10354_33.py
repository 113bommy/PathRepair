import sys
input = sys.stdin.readline
n = int(input())
o = list(map(int,input().split()))
l = [0]+o
ans = 0
e = 0
for i in range(n):
    x = l[i]-l[i+1]
    e += x
    if e < 0:
        ans = abs(e)
        e = 0

print(ans)
