n,m=map(str,input().split());s,k=n,m;print(s,k)
for i in range(int(input())):
    q,w=map(str,input().split())
    if s==q:s,k=w,q;print(s,k)
    else:k=w;print(s,k)