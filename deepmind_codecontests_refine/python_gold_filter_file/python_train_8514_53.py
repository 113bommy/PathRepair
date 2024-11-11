s = input()
t = input()

x = len(s)
y = len(t)

a = 0
b = x
c = 0
a0 = 0


for i in range(0,y):
  while True:
    #先頭からの位置
    a=s.find(t[i:i+1],a0)+1
    if a <= 0:
      a=s.find(t[i:i+1])+1
    if a <= 0:
      print("-1")
      exit()
    
    if a<=a0:
      c=c+a+b
    else:
      c=c+a-a0
    b=x-a
    a0=a
    break
    
print(c)
