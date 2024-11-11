import sys
input = sys.stdin.buffer.readline

n = int(input())
a = list(map(int, input().split()))

psm, ssm = [0]*n, [0]*n
for i in range(n):
    psm[i] = a[i] + (psm[i-2] if i-2 >= 0 else 0)
for i in range(n-1, -1, -1):
    ssm[i] = a[i] + (psm[i+2] if i+2 < n else 0)

mx, total = 0, sum(a)
for i in range(1, n):
    sm = (psm[i-3] if i-3 >= 0 else 0) + ssm[i]
    mx = max(mx, total-sm)
mx = max(mx, total-ssm[0]+a[-1])

print(mx)