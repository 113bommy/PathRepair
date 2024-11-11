L=[]
M=[]
for i in range(5) :
  A=int(input())
  L.append(A)
  if A%10!=0 :
    M.append(10-A%10)
print(sum(L+M)-max(M))