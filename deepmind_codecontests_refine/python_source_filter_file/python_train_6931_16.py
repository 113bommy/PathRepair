a=int(input())
z=[0]+[0]*a
if a<3:print(1)
else:print(2)
for i in range(2,a+1):
    if not(z[i]):
        for j in range(i,a+1,i):z[j]=2
        z[i]=1
print(*z[1:])
