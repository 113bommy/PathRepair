N = int(input())

t = 0

for i in range (1,N+1):
  p = N//i
  t += i*p*(1+p)/2
  

print(int(t))