n = int(input())
d = int(input())
e = int(input())
i=0
fin=n
while i*5*e<=n:
  left=(n-i*5*e)%d
  fin=min(fin,left)
  i+=1
print(fin)