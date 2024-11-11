t = list(map(int,input().split()))
n = t[0]
a = t[1]
b = t[2]
if a + b < n:
    print(b + 1)
else:
    print(n-a)