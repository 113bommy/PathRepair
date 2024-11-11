import sys
p, d = map(int, sys.stdin.readline().split())
k = 10
n = p
while p>=k and p%k-1<=d:
    if p%k < k-1:
        n = p-p%k-1
    k*=10
print (n)
