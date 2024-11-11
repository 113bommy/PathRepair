N = int(input())
A = []
for i in range(int(N**0.5)):
  if N%(i+1) == 0:
    A.append(i)
print(len(str(int(N/A[-1]))))
