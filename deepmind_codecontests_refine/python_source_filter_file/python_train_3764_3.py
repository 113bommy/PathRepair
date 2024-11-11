#Codeforces 1154A
x,y,z,w=[int(v) for v in input().split()]
d=[x,y,z,w]
d.sort()
a = d[3]-d[0]
b = d[2]-d[0]
c = d[1]-d[0]
print(str(a)+" "+str(b)+" "+str(c))