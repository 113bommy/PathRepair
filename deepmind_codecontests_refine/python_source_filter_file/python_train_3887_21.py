x=int(input(""))
r=input("").split(' ')
r=[int(x) for x in r]
r.sort()
summ=0
for g in range (len(r)):
    summ+=r[g]
count=0
needed=0
if (summ%2==0):
    needed=summ/2
else:
    needed=(summ//2)+1
ans=0
for g in range (len(r)-1,-1,-1):
    count+=r[g]
    ans+=1
    if (count>=needed):
        print(ans)
        break
