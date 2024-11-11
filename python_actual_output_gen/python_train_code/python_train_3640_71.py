n,k = map(int,input().split())
m = 1
while n > k**m:
    m += 1
print(m)