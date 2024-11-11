def mask(x):
 s = 0
 n = str(x)
 for i in range(len(n)):
     if n[i] == '7' or n[i] == '4':
         s = s * 10 + int(n[i])
 return s
a , b = (input().split())
a= int(a)
a= a + 1
b= int(b)
while mask(a) != b:
    a = a + 1
print(a)