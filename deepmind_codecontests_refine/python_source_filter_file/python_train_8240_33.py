n=int(input())
for i in range(n):
    l=list(map(int,input().strip().split()))
    s=sum(l)
    print(s/2)
