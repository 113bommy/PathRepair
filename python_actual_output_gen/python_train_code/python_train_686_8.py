n=int(input())
s=input()
t=''
for i in s:
  x=chr((ord(i)-65)%26+65-n)
  t+=x
print(t)
