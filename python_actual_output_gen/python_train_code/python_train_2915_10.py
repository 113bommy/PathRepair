n=int(input())
l=list(map(int,input().split()))
d={}
error=0
l.sort()
for i in l:
    if i==5 or i==7:
        error+=1
    if i not in d:
        d[i]=0
    d[i]+=1
if l.count(1)!=int(n/3) or l.count(2)+l.count(3)!=int(n/3) or len(d)<3  or error>0 or (l.count(3)>0 and l.count(3)!=l.count(6)):
    print("-1")
else:
    for i in range(int(n/3)):
        for j in range(i,n,int(n/3)):
            print(l[j],end=" ")
        print()

    
    
        
        
            