n=int(input())
for _ in range(n):
    m=int(input())
    print(m)
    l=list(range(1,m+1))
    print(*l[::-1])