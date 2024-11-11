n=int(input())

for i in range(n):
    x,y=map(int,input().split())
    a,b=map(int,input().split())
    ans=[]
    if x>y:
        ans.append((x-y)*a+x*b)
        ans.append((x-y)*a+y*b)
        ans.append(x*a+y*b)
        print(min(ans))
    else:
        x,y=y,x
        ans.append((x-y)*a+x*b)
        ans.append((x-y)*a+y*b)
        ans.append(x*a+y*b)
        
        print(min(ans))
