n, m = [int(x) for x in input().split()]

f = [0] * m
f = [int(x) for x in input().split()] 

f.sort()

#The window size is n. So we check the minimum for each window range.

least = f[n-1] - f[0]

for i in range(0, m-n):
    least = min(least,f[i+n-1] - f[i])

print(least)
