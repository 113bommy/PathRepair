N = int(input())
n = int(N**0.5)

while N%n:
  n-=1

print(len(str(N//n)))