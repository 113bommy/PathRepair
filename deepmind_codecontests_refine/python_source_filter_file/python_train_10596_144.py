n,k = map(int,input().split())
a = 0
while k**a < n:
    a += 1
print(a)