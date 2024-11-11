n=int(input())
l=[]
while(n):
  n-=1
  x=n%26
  l.insert(0,chr(( x-1) + ord('a')))
  n//=26
print("".join(l))
