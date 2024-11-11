c=0
for _ in range(int(input())):
    m,n=map(int,input().split())
    if n-m>=2:
        ++c
print(c)