import sys
input = sys.stdin.readline
n,h,m=list(map(int,input().split()))
a = [h]*n
for i in range(m):
    b,c,d = list(map(int,input().split()))
    a[b-1:d] = [min(x,d) for x in a[b-1:d]]
print(sum([x**2 for x in a]))