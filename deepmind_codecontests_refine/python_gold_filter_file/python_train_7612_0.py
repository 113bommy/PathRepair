n,l,r=[int(x) for x in input().split()]
m=1000000007
if r%3==0:
    count1=r//3
    count2=r//3
    count3=r//3
elif r%3==1:
    count1=r//3 +1
    count2=r//3
    count3=r//3
else:
    count1=r//3 +1
    count2=r//3 +1
    count3=r//3
rcount1=count1
rcount2=count2
rcount0=count3

l-=1

if l%3==0:
    count1=l//3
    count2=l//3
    count3=l//3
elif l%3==1:
    count1=l//3 +1
    count2=l//3
    count3=l//3
else:
    count1=l//3 +1
    count2=l//3 +1
    count3=l//3
lcount1=count1
lcount2=count2
lcount0=count3

finalcount1=rcount1-lcount1
finalcount2=rcount2-lcount2
finalcount0=rcount0-lcount0

dp0=[0]*200001
dp1=[0]*200001
dp2=[0]*200001

dp0[0]=finalcount0
dp1[0]=finalcount1
dp2[0]=finalcount2
# print(finalcount0,finalcount1,finalcount2)
for i in range(1,n):
    dp0[i]=(dp0[i-1]*finalcount0)%m
    dp0[i]=(dp0[i]+(dp1[i-1]*finalcount2)%m)%m
    dp0[i]=(dp0[i]+(dp2[i-1]*finalcount1)%m)%m

    dp1[i]=(dp1[i-1]*finalcount0)%m
    dp1[i]=(dp1[i]+(dp0[i-1]*finalcount1)%m)%m
    dp1[i]=(dp1[i]+(dp2[i-1]*finalcount2)%m)%m

    dp2[i]=(dp0[i-1]*finalcount2)%m
    dp2[i]=(dp2[i]+(dp1[i-1]*finalcount1)%m)%m
    dp2[i]=(dp2[i]+(dp2[i-1]*finalcount0)%m)%m
ans=dp0[n-1]
print(ans)