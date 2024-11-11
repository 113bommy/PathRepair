l=[]
for i in range(3):
    l.append(int(input()))
m=max(l[0]+l[1],l[0]*l[1])
m=max(m*l[2],m+l[2])
n=max(l[1]+l[2],l[1]*l[2])
n=max(m*l[0],m+l[0])
print(max(m,n))