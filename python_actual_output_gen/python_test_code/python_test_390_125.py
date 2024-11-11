a=0
for i in range(1,int(input())+1):
  a+=(not (i%3 or i%5))*i
print(a)