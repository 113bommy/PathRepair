s,n=map(int,input().split())
l=list(map(int,input().split()))
r=list(map(int,input().split()))
ans=0
if(l[0]==1):
    if(l[s-1]==1):
        print("YES")
    else:
        for j in range(s,n):
            if (l[j]==1 and r[j]==1):
                ans=1
        if(ans and r[s-1]==1):
            print("YES")
        else:
            print("NO")
else:
    print("NO")
