N,P = map(int,input().split())
A = [int(x) for x in input().split()]

odd = sum(x&1 for x in A)

if odd:
  # どちらも半分ずつ
  answer = 2**(N-1)
else:
  answer = (2 ** N) * P

print(answer)