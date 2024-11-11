n,m=map(int,input().split())
count=m
s=0
for _ in range(n):
    a,b=map(str,input().split())
    if a=="+":
        count+=int(b)
    else:
        if count-int(b)>0:
            count-=int(b)
        else:
            s+=1    
print(count,s)        