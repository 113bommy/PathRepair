n=int(input())
for i in range(n):
    l=list(map(int,input().split()))
    s=sum(l)
    print(s//2)
