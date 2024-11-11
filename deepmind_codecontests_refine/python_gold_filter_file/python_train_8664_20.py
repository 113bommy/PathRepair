from sys import stdin

n, k = map(int, stdin.readline().rstrip().split(" "))
l = list(map(int, stdin.readline().rstrip().split(" ")))
free = n
total = sum(l)
if sum(l)<n:
    x = [-1]
else:
    x = [0]*k
    for i in range(k-1,-1,-1):
        x[i]= max(free - l[i], i)+1
        free=x[i]-1
    for i in range(k):
        if l[i] > n - i:
            x = [-1]
print(*x)