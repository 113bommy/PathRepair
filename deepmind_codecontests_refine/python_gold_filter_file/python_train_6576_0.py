from collections import*
for _ in[0]*int(input()):
 s,t,p=input(),input(),Counter(input());i=0
 for c in t:
  if i<len(s)and c==s[i]:i+=1
  elif p[c]:p[c]-=1
  else:i=0;break
 print('YNEOS'[i<len(s)::2])