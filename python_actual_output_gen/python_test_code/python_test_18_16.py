


n,k = map(int,input().split())

list = []
temp = 0
if k%n != 2:

 for a in range(n+1):
  for b in range(n+1):
    for c in range(n+1):
        for d in range(n+1):
            if 2*a+4*c+3*b+5*d == k and a + b + c + d == n:

                print(a)
                temp = 1
                break
        if temp == 1:
            break
    if temp == 1:
        break
  if temp == 1:
     break
else:
    print(n)
