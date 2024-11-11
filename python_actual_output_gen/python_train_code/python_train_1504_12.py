n=int(input())

s=''
while n:
  n-=1
  s=chr(65+n%26)+s
  n//=26
  
print(s)