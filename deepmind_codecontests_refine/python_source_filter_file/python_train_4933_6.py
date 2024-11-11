n,s,t=map(int,input().split())
list1=list(map(int,input().split()))
list1=[0]+list1
c=0
if(list1[s]==t):
    print(0)
else:
    x=list1[s]
    c+=1
    while(x!=t and x!=s):
        c+=1
        x=list1[x]
        
    if(x==t):
        print(c)
    else:
        print(-1)