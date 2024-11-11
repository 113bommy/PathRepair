S=input()
K=int(input())
N=len(S)

i=0
while i<N:
  if S[i]=='1':
    i+=1
  else:
    print(S[i])
    exit()
    
print(1)