import sys
n = int(input())
a = list(map(int, sys.stdin.readline().split()))
b = [0]*n
for i in range(n-2,-1,-1):
  b[i] = max(a[i+1],b[i+1])
c = [b[i]+1-a[i] for i in range(n)]
c[-1] = 0
print(' '.join([str(i) for i in c]))
