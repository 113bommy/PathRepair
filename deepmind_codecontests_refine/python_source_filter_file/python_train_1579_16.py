n=int(input())
l=list(map(int,input().split()))
a=l.count(1)
b=l.count(2)
if a==0 or b==0:
    print(*l)
else:
    print(2,1,*[2]*(a-1),*[1]*(b-1))
    
