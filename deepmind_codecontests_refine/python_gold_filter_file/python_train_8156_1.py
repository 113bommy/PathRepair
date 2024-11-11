x,y,a,b = list(map(int,input().split()))
a = max(a,b+1)
c = []
s = 0
for i in range(a,x+1):
    for j in range(b,min(i,y+1)):
        c.append((i,j))
        s+=1
if s == 0:
    print(s)
else:
    print(s)
    for i,j in c:
        print(i,j)