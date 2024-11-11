n = int(input())
s=''
while n!=0:
  tmp=n%26
  s=chr(96+tmp)+s
  n//=26
print(s)