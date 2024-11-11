N=int(input())
A=[]
for i in range(2,55556):
  if i%5==1:
    j=2
    while j<i:
      if i%j==0:
        break
      j+=1
    if i-j==0:
      A.append(i)
  if len(A)>=N:
    break
print(A[:N])