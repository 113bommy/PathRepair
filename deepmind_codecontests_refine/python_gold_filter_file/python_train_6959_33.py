N = int(input())
A = []
for i in range(int(N**0.5)):
  if N%(i+1) == 0:
    A.append(i+1)
print(len(str(int(N/A[-1]))))
