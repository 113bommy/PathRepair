n = int(input())

a = list(int(input()) for i in range(n))
a = sorted(a)
A = sum(a)
if A%10!=0:
  print(A)
else:
  for i in range(n):
    if(A-a[i])%10!=0:
      print(A-a[i])
      exit()
print(0)