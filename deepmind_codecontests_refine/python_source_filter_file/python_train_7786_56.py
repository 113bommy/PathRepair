S = int(input())

A = 10**9
C = S//A
Bt = S%A

if Bt!=0:
  C += 1
  B = A - Bt

ANS = [0, 0, A, 1, B, C]
print(*ANS)
