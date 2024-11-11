N = int(input())

x = []
for i in range(1, int((N+1)**0.5)+1):
  if N % i == 0:
    x.append(i)

y = int(N/x[-1])
print(len(str(y)))
