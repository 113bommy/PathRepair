n=int(input())
s=input()
t=input()
if s==t:
  print(n)
  exit()
for i in range(1,n-1):
  if s[i+1:] == t[:-i-1]:
    print(n+i)
    break