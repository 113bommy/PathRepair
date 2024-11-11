N = int(input())
A = sorted(list(map(int,input().split())))
B = (10**6+1)*[0]

for a in A:
  B[a]+=1
  if B[a]==1:
    for n in range(2*a,10**6+1,a):
      B[n]+=1

print(B.count(1))