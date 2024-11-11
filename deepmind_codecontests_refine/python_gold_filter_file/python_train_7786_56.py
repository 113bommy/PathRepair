S = int(input())

A = 10**9
C = S//A
B = S%A

if B!=0:
  C += 1
  B = A - B

ANS = [0, 0, A, 1, B, C]
print(*ANS)
