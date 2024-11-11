n,h=map(int,input(2).split())
a=list(map(int,input().split()))
c=0
for i in range(n):
    if(a[i]>h):
        c+=2
    else:
        c+=1
print(c)        
