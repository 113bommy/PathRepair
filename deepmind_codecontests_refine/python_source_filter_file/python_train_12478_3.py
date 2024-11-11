n=int(input())
s=input()
t=input()
for i in range(n,2*n+1):
  a=s[:i]+t[i-n:]
  if a[-n:]==t:exit(print(i))