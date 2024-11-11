a=input()
n=len(a)
ans=1
c=0
for i in range(n-1):
    if int(a[i+1])+int(a[i])==9:
        c+=1
    else:
        if c%2==0 and c!=0:
            # print(c+1)
            ans*=(c+1)//2+1
        c=0

if c%2==0 and c!=0:
    ans*=2
print(ans)
