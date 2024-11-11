n=int(input())
s=''
while n:
  s=chr(96+n%26)+s
  n//=26
print(s)