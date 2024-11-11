S = list(input())
s = len(S)
K = int(input())
A = []
j = 1

for i in range(0,s-1,1):
  if S[i] == S[i+1]:
    j += 1
  else:
    A.append(j)
    j = 1
A.append(j)

a = len(A)

b = 0
for i in range(0,a,1):
  b += A[i]//2
  
x = b*K

if a == 1:
  x = (s*K)//2
elif S[s-1] == S[0] and A[a-1] % 2 == 1 and A[0] % 2 == 1:
  x += K-1

print(x)