n=int(input())
s="1"+input()
a=[]
for i in range(n):
  if s[i]!=s[i+1]:a+=[1]
  else:a[-1]+=1
x=3
for i in range(1,len(a)):
  if a[i-1]==a[i]==1:x*=2
  elif a[i-1]==a[i]==2:x*=3
  elif a[i]==1:x*=1
  else:x*=2
  x%=10**9+7
print(x)