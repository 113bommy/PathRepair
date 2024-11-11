N = int(input())
A = list(map(int, input().split()))
B = list(map(int, input().split()))

Achange = []
Bchange = []

for i in range(3):
  if A[i] > B[i]:
    Bchange.append(i)
  elif A[i] < B[i]:
    Achange.append(i)

#print(Achange, Bchange)

# 最初のA交換所→B交換所
Dmax1 = N
if Achange:
  if len(Achange)==3:
    i = Achange[0]
    j = Achange[1]
    k = Achange[2]
    for x in range(N+1):
      for y in range(N+1):
        if A[i]*x+A[j]*y <= N:
          Dmax1 = max(Dmax1, B[i]*x + B[j]*y + (N-A[i]*x-A[j]*y)%A[k] + (N-A[i]*x-B[j]*y)//A[k] * B[k])
    
  if len(Achange)==2:
    i = Achange[0]
    j = Achange[1]
    for x in range(N+1):
      if A[i]*x <= N:
          Dmax1 = max(Dmax1, B[i]*x + (N-A[i]*x)%A[j] + (N-A[i]*x)//A[j] * B[j])
    
  if len(Achange)==1:
    i = Achange[0]
    Dmax1 = max(Dmax1, N%A[i] + (N//A[i] * B[i]))
    
#print(Dmax1)
#print(Achange, Bchange)
#次のB交換所→A交換所
Achange = Bchange
A,B=B,A
N = Dmax1
#print(Achange, Bchange)

if Achange:
  if len(Achange)==3:
    i = Achange[0]
    j = Achange[1]
    k = Achange[2]
    for x in range(N+1):
      for y in range(N+1):
        if A[i]*x+A[j]*y <= N:
          Dmax1 = max(Dmax1, B[i]*x + B[j]*y + (N-A[i]*x-A[j]*y)%A[k] + (N-A[i]*x-B[j]*y)//A[k] * B[k])
    
  if len(Achange)==2:
    i = Achange[0]
    j = Achange[1]
    for x in range(N+1):
      if A[i]*x <= N:
          Dmax1 = max(Dmax1, B[i]*x + (N-A[i]*x)%A[j] + (N-A[i]*x)//A[j] * B[j])
    
  if len(Achange)==1:
    i = Achange[0]
    Dmax1 = max(Dmax1, N%A[i] + (N//A[i] * B[i]))
    
print(Dmax1)
 