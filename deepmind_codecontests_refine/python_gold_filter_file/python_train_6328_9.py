N = int(input())
C = [0]*100
for i in range(1,N+1):
  s = str(i)
  C[10*int(s[0])+int(s[-1])] += 1
print(sum([C[10*i+j]*C[10*j+i] for i in range(10) for j in range(10)]))
