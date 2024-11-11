S=input()
for c in"abcdefghijklmnopqrstuvwxyz":
 if(c in S)^1:print(S+c);quit()
for i in range(1,26):
 for c in sorted(S[-i:]):
  if c>S[-i]:print(S[:-i]+c);quit()
print(-1)