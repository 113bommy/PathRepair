s=input()

a=0
ab=0
abc=0
q=1
m=10**9+7

for i in range(len(s)):
  if s[i]=="A":
    a=(a+q)%m
  elif s[i]=="B":
    ab=ab+a
  elif s[i]=="C":
    abc=(abc+ab)%m
  else:
    abc=(abc*3+ab)%m
    ab=ab*3+a
    a=(a*3+q)%m
    q=(q*3)%m
print(abc)
