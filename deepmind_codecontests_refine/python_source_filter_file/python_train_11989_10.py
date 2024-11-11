from math import factorial as f
a = int(input())
b = ""
for x in range(0,a):
    c = input()
    b += c[0]
d = list(set(b))
e = 0
for y in range(0,len(d)):
    i = b.count(d[y])
    l = i//2
    m = i-l
    if(i==2):
        e+=1
    elif(i==3):
        e+=1
    elif(i!=1 and i!=2 ):
        e+= (f(l)/(f(2)*f(l-2)))+(f(m)/(f(2)*f(m-2)))


print(int(e))
