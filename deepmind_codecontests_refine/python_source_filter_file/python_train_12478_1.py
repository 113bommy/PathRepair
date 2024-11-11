n=int(input())
s=input()
t=input()
ans=0
for i in range(n):
  if s[i:] == t[:n-i]:
    ans = n-i
print(2*n-ans)