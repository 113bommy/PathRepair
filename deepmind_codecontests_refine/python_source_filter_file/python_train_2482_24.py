import sys
s=input()
T=input()
for i in range(len(s)-len(T)+1,0,-1):
  for j in range(len(T)):
    if T[j]!=s[i-1+j] and "?"!= s[i-1+j] :
      break
  else:
    s=s[:i-1]+T+s[i+len(T):]
    s = s.replace('?', 'a')
    print(s)
    sys.exit()
else: print("UNRESTORABLE")