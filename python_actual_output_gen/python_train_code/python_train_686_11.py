n=int(input())
s = list(input())
for l in s:
  m = ((ord(l)-64)+n)%26+64
  s = chr(m)
  print(s,end="",sep="")