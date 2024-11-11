def factorization(n):
    arr = []
    temp = n
    for i in range(2, int(-(-n**0.5//1))+1):
        if temp%i==0:
            cnt=0
            while temp%i==0:
                cnt+=1
                temp //= i
            arr.append([i, cnt])

    if temp!=1:
        arr.append([temp, 1])

    if arr==[]:
        arr.append([n, 1])

    return arr

sosuu=[2];n=int(input())
for L in range(3,n):
    chk=True
    for L2 in sosuu:
        if L%L2 == 0:chk=False
    if chk==True:sosuu.append(L)
S=set(sosuu)




A=[0]*(n+1)
g=0
for i in range(n+1):
  A[i]=int(input())
P=[]
PP=factorization(abs(A[0]))
for i in range(len(PP)):
  P.append(PP[i][0])
if P==[1]:
  P=[]
P=set(P)
P=S|P
P=list(P)
P.sort()
for i in range(len(P)):
  p=P[i]
  B=A[0:n+2]
  b=0
  for j in range(n+1):
    if p+j<n+2:
      B[j+p-1]=(B[j+p-1]+B[j])%p
    else:
      if A[j]%p!=0:
        b=1
        break
  if b==0:
    print(p)