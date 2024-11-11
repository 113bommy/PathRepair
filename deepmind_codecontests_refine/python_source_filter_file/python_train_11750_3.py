S=input()
N=len(S)
ans=0
for i in range(2**(N-1)):
  S=S[0]
  q="{:0>10b}".format(i)[::-1]
  for j in range(1,N):
    if int(q[j-1])&1:
      F+="+"
    F+=S[j]
  ans+=eval(F)    
print(ans)