a = input()
b = input()
b = b.split()
c = [] 
for i in b:
    c.append(int(i))

c.sort()

c.reverse()
d = int(b[0])
for i in range(1,int(a)):
    d=d-int(c[i])
    
print (d+1)
