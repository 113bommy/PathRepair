import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int,input().split()))

if n == 1:
    print(a[0])
    exit()
b = [0]
cnt = 0
idx = 0
while cnt <= n+5:
    b.append(b[-1]+a[idx])
    cnt += 1
    idx += 2
    if idx >= n:
        idx -= n

res = b[-1]
for i in range(len(b)):
    if i+n//2 >= len(b):
        break
    res = min(res,b[i+n//2]-b[i])

print(sum(a) - res)