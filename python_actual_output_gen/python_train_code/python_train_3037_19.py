N=int(input())
print(sum((N//i)*(N//i*1)//2)*i for i in range(1,N+1))
