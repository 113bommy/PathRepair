n,a,ans,last=int(input()),[],[],1000
for i in range(n):a.append(input())
for d in a:
    minoverd=10000000
    for i in range(10):
        for j in range(i==0,5):
               t=int(d[:j]+str(i)+d[j+1:])
               if minoverd>t>=last:minoverd=t
    ans.append(str(minoverd))
    if minoverd>2011:break
    last=minoverd
if minoverd>2011:
               print("No solution")
else:
               print(*ans)
