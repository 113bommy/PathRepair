n=int(input())
s=list(input())
a=""
for c in s:
  a+=chr((ord(c)-ord(a)+n)%26+ord(a))
print(a)
  