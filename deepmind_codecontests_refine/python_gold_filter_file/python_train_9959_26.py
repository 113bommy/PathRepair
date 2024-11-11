n,k=map(int,input().split())
list1=list(map(int,input().split()))
s1=0
s2=k
ss1=0
ss2=0
s=0
f=0
for i in range(n):
    # if(list1[i]>0):
    #     # ss2=0
    #     ss1+=list1[i]
        
    # else:
    #     ss2+=abs(list1[i])
    #     # ss1=0
    if(list1[i]>k or list1[i]<-k):
        f=1
    s+=list1[i]
    
    if(s>k or s<-k):
        f=1
        
    if(s<0):
        s1=max(s1,abs(s))
    else:
        s2=min(s2,k-s)
    # if(ss1>s1):
    #     s1=ss1
    # if(ss2>s2):
    #     s2=ss2
    
if(s1<=s2 and f==0):
    print(s2-s1+1)
else:
    print(0)