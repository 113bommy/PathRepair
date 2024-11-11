a=[str(i) for i in input().split()]
ans=''
ans+=a[0][0]
for i in range(1,len(a[0])):
    if(ord(a[0][i])<=ord(a[1][0])):
        ans+=a[0][i]
    else:
        break
ans+=a[1][0]
print(ans)
