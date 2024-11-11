a=int(input())
z=[0]*(a+1);k=2
for j in range(2,a+1,2):z[j]=1
for i in range(3,a+1,2):
    if z[i]==0:
        for j in range(i,a+1,i):z[j]=k
        k+=1
z.pop(0);z.pop(0)
print(*z)