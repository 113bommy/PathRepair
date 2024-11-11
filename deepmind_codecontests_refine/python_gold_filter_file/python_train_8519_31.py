n=int(input())
lists=list(map(int,input().split()))
from collections import Counter
a=dict(Counter(lists))
if len(a)==1:
    if n>=lists[0]*2 or lists[0]==n-1:
        print("Yes")
    else:
        print("No")
    
elif len(a)==2:
    P=list(a.keys())
    Q=list(a.values())
    x,y=min(P),max(P) #x=k+l-1,y=k+l
    c,d=a[x],a[y]#c=k,d=?
    if 2*y-c<=n and c>0 and y>c and y-x==1:
        print("Yes")
    else:
        print("No")

    
else:
    print("No")