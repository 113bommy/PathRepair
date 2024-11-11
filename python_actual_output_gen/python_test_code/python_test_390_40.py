N=int(input())

print(sum(i for i in range(1,N+1) if i%3==0 or  i%5==0))