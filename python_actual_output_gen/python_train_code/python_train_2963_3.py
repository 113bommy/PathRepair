n,k=map(int,input().split())
s=input()
a=sorted(s)
if k>n:r=s+a[0]*(k-n)
else:
    for i in range(k-1,-1,-1):
        if s[i]!=a[-1]:
            r=s[:i]+a[a.index(s[i])+1]+a[0]*(n-i-1)
            break
print(r)