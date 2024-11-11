n=int(input())
s=input()
c=[]
b=[0,1,3,6,10,15,21,28,30,45]
for i in b:
  if(i<n):
    c.append(s[i])
str1 = ''.join(str(e) for e in c)
print(str1)