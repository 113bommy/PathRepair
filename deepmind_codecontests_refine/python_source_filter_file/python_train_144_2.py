a=[int(x) for x in input().split()]
b=[int(x) for x in input().split()]

c=[]
for i in range(len(b)-1):
    c.append(b[i]-b[i+1])

if(max(c)>0):
    print(max(c)-a[1])
else:
    print(0)
    
    
