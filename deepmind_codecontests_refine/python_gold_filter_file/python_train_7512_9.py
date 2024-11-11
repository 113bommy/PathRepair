from sys import stdin
read = stdin.readline


n,k = map(int,read().split())

a = list((map(int,read().split())))

b = sorted((a[i+1]-a[i] for i in range(n-1)))


print(a[-1]-a[0]-sum(b[n-k:]))
