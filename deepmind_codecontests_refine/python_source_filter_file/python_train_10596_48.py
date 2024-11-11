,k = map(int,input().split())
a = 1
while k**a < n:
    a += 1

print(a)