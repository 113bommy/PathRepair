n=int(input())
a=list(map(int,input().split()))
a.sort()
x=sum(a)
m=int(input())
q=list(map(int,input().split()))
for i in q:
    print(x-a[i])
    
    