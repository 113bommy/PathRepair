N = int(input())
sum = 0
for i in range(1,N+1):
  sum+=i*(1+N//i)*(N//i)/2
print(int(sum))