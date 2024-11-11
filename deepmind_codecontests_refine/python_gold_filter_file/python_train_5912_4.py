N,K,C= map(int,input().split())
S = input()
T = [n for n, v in enumerate(S) if v == "o"]

a,b=[T[0]],[T[-1]]

for i in range(len(T)):
  if len(a)!=K:
    if T[i]-a[-1]>C:
      a.append(T[i])
  if len(b)!=K:
    if b[-1]-T[-i-1]>C:
      b.append(T[-i-1])
      
for i in range(K):
  if a[i]==b[-i-1]:
    print(a[i]+1)
  