n=int(input())
a=list(map(int,input().split()))
b=[]
c=0
for i in range(len(a)-1):
    if(a[i]<=a[i+1]):
        c=c+1
        
    else:
        c=0
    b.append(c)
if(len(a)>1):    
    print(max(b)+1)
else:
    print("0")
        
    