s=list(input())
K=int(input())
 
ANS = 1
for i in range(K):
  if s[i] != '1':
    ANS = int(s[i])
    break
print(ANS)