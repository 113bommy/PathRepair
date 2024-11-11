l1,r1,l2,r2,k=map(int,input().split())
if(l2>=r1 or r2<=l1):
    print(0)
else:
    if (max(l1,l2)<=k and k<=min(r1,r2)):
        print(min(r1,r2)-max(l1,l2))
    else:
        print(min(r1,r2)-max(l1,l2)+1)