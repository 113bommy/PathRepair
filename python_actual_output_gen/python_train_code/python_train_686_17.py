n=int(input())
s=input()
a=""
for i in s:
  a+=chr(65+(ord(i)+n)%26)
print(a)