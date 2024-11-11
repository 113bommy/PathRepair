n,k=map(int,input().split())
s=input()
res=1
#For a
p1=0
p2=1
ck=0
while(p2<n and p1<n):
    if((s[p2]=='b' and ck<=k) or s[p2]=='a'):
        if(s[p2]=='b'):
            ck+=1
        p2+=1
        l=p2-p1
        #print(l)
        if(l>res):
            res=l
    else:
        if(s[p1]=='b'):
            ck-=1
        
        p1+=1
#For b
p1=0
p2=0
ck=0
while(p2<n):
    if((s[p2]=='a' and ck<k) or s[p2]=='b'):
        
        if(s[p2]=='a'):
            ck+=1
        p2+=1
        l=p2-p1
        #print(l)
        if(l>res):
            res=l
    else:
        if(s[p1]=='a'):
            ck-=1
        
        p1+=1
        
    
print(res)
