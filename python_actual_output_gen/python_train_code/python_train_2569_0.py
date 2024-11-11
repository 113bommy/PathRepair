n,d=map(int,input().split())
l=list(map(int,input().split()))
m=int(input())
if m==n:
    s=sum(l[:n])
elif m>n:
    s=sum(l[:n])-(m-n)*d
elif m<n:
    s=sum(l[:m])
print(s)
