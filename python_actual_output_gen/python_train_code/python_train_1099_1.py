a,b=[],[]
for i in range(int(input())):
    x,y=input().split()
    a.append(int(x))
    b.append(int(y))
print(max(max(b)-min(b),max(b)-min(b))**2)