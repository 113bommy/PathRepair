s,n=map(int,input().split())
count=0
l=[]
if n==1:
    a,b=map(int,input().split())
    if s<a:
        print("NO")
    else:
        print("YES")
else:
    for i in range(n):
        a,b=map(int,input().split())
        l.append([a,b])
    l.sort()
    for i in range (len(l)):
        if l[i][0]<=s:
            count=count+1
            s=s+l[i][1]
    if count==n:
        print("YES")
    else:
        print("NO")