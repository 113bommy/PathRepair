a,b=map(int,input().split())
if b>0:
    l=list(map(int,input().split()))
    l.sort()
    if l[0]==1 or l[-1]==a:
        print("NO")
        exit(0)
    for i in range (b-2):
        if l[i]+1==l[i+1] and l[i+1]+1==l[i+2]:
            print("NO")
            exit(0)
    print("YES")
else:
    print("YES")