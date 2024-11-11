m=input()
a=int(m[0])-1+(len(m)-1)*9
b=0
for i in n:
  b+=int(i)
print(max(b,a))
