n = int(input())
s = input()
r = 0
status = 0
c = 0
for i in s:
   if i=='U':
       r+=1
   else:
       r-=1
   if r>0:
       if status == 1:
           c+=1
       status = 2
   if r<0:
       if status == 2:
           c+=1
       status = 1
print(c)
 



