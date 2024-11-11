n=int(input())
s=input()
t=input()
for i in range(n):
  if s[i:-1] == t[:n-i]:
    print(n+i)
    quit(0)
    
print(2*n)