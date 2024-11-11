z,w,m=input,int,sorted
n=w(z())
l1=list(map(int,input().split()))
l2=set(l1)
l={}

for i in l2:
    l[i]=0
for i in l1:
    l[i]+=1
l=sorted(l.values())
l=l[::-1]
c=0
ans=0

for i in l:

    ans+=(i+c)//4
    c=(c+i)%4
    
    if c>=2 :
        c=2
    else:
        c=0


    
print(ans)   
        


    
    

