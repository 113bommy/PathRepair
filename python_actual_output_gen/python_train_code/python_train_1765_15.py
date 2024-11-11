n,s=map(int,input().split())
a=list(map(int,input().split()))
b=list(map(int,input().split()))

if a[0]==1 and a[s-1]==1:
    print("YES")
elif a[0]==1 and b[s-1]==1 and any(a[i]==1 for i in range(s,n)):
    print("YES")
else:
    print("NO")