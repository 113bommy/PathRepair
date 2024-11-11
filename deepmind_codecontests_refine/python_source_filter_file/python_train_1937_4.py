n=int(input())
 
a=list(map(int,input().split()))
 
a.sort()
# print(a[:3])

x= list(set(a[0:3]))
if len(x)==1:
    c=a.count(x[0])
    print(c*(c-1)*(c-2)//6)
if len(x)==2:
    
    c = a.count(x[0])
    c1=a.count(x[1])
    if c==1:
        
        print(c1*(c1-1)//2)
    else:
        
        print(c)
if len(x)==3:
    c=a.count(x[2])
    print(c)