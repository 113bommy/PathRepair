N=int(input())
sum=0
for j in range(1,N+1):
    sum+=int(((N//j)*(N//j+1)/2)*j)
print(sum)
