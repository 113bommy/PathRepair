from sys import stdin
input = stdin.readline

n, k = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]

diff = [(a[i]-a[i-1]) for i in range(1, n)]
diff = sorted(diff)

res = 0
for i in range(k):
    res += diff[i]
    
print(res+a[n-1]-a[0])