n = int(input())
lis=[int(x) for x in input().split()]
su=[]
ma=1
for i in range(n):
    for j in range(i+1,n):
        su.append(lis[i]+lis[j])
su = sorted(su)
cou=1
for i in range(len(su)-1):
    if su[i]==su[i+1]:
        cou+=1
#        print(su[i])
    else:
        if cou>ma:
            ma=cou
        cou=1    
print(ma)        