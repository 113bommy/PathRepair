n=int(input())
sum=0
u=list(map(int,input().split()))
u.sort()
sum=u[0]
p=1
for i in range(1,n):
    if(sum<=u[i]):
        sum+=u[i]
        p+=1
    else:
        continue
print(p)    