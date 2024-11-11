S=input()
N=len(S)
SH=S[:(N-1)//2]
ST=S[(N+3)//2-1:]
p=False
if SH==SH[::-1] and ST==ST[::-1]:
  p=True
print("Yes" if p else "No")