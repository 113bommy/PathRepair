N=int(input())
S=input()
r,g,b = S.count('R'),S.count('G'),S.count('B')
total = r*g*b

count = 0
for d in range(1,N//2):
  for i in range(N-2*d):
    if S[i]!=S[i+d] and S[i+d]!=S[i+2*d] and S[i+2*d] != S[i]:
      count+=1

print(total-count)
      