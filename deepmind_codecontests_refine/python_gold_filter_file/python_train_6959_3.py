N = int(input())
P = [i for i in range(1, int(N**.5)+1)][::-1]
for i in P:
  if N%i == 0:
    print(len(str(N//i)))
    break