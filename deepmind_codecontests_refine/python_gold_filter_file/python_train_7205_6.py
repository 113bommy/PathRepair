qtd=int(input())

for i in range(qtd):
  A, B, C, N=map(int, input().split())

  maior=max(A, B,C)
  aux=(maior-A)+(maior-B)+(maior-C)

  if (N>=aux and (N-aux)%3==0):
    print("YES")

  else:
    print("NO")