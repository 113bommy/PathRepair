n = int(input())
s = 0
ar = [int(i) for i in input().split()]
m = max(ar)
for i in range(n):
    s += ar[i]-m
print(s)
