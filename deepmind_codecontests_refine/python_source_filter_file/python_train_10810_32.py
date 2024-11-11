s=input()
while(1):
  s=s[:-2]
  l=len(s)
  if s[:l/2]==s[l/2:]:
    print(l)
    break
