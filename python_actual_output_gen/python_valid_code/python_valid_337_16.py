n=int(input())
s=input()
a=1
for i in range(n):
  if s[i]!=s[i+1]:
    a+=1
print(a)