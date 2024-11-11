s=input()
for i in range(len(s)//2-1,0,-1):
  if s[0:i]==s[i:i+i]:
    print(i)
    exit(0)
