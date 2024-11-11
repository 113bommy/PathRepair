n=int(input())
s=input()
k=int(input())
a=''
b=s[k-1]
for i in s:
  if i==b:a+=i
  else:a+='*'
print(a)