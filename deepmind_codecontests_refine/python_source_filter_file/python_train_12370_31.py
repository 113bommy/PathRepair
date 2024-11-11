N = int(input())
a = []
if N == 0:
  a.append["0"]
while N != 0:
  a.append(str(N % 2))
  N = -(N // 2)
print("".join(reversed(a)))