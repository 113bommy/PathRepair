n,a,b=(int(x) for x in input().split())
if b>0:
    ans=(a-1+b)%n+1
else:
    b*=-1
    steps=b%n
    back=a-1
    if steps<=back:
        ans=a-back
    else:
        rem=steps-back
        ans=n+1-rem

print(ans)
