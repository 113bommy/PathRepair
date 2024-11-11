t=int(input())
for i in range(t):
    n,m=map(int,input().split())
    li=[int(num) for num in input().split(" ",n-1)]
    k=sum(li)-li[0]
    l=m+k
    
    print(min(l,m))