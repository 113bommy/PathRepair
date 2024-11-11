S=input()
num=0
for i in range(len(S)//2):
  if S[i]!=S[-i]:
    num+=1
print(num)
  
