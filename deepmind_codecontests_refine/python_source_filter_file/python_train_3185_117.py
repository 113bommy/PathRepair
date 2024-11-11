n,m = map(int, input().split())
c = 0
while n < m:
    n*=3
    m*=2
    c+=1
print(c)