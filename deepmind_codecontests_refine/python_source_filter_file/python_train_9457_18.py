n=int(input())
S=sorted([int(input()) for i in range(n)])
not_10=[i for i in S if i%10!=0]
sums=sum(S)
if sums%10!=0:
  print(sums)
else:
  print(sums-(not_10[0] if not_10 else 0))
