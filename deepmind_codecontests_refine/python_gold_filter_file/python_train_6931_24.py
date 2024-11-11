a=int(input())
z=[0]+[0]*(a+1)
if a<3:print(1)
else:print(2)
for i in range(2,a+2):
    if not(z[i]):
        for j in range(i,a+2,i):z[j]=2
        z[i]=1
print(*z[2:])
