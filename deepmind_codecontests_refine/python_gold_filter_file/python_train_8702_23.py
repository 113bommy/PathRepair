l=input().split()
a=[]
b=[]
for i in range(0,4):
    a.insert(i,int(l[i]))
m=input().split()
for i in range(0,2):
    b.insert(i,int(m[i]))
x=abs(a[0]-a[2])%b[0]
y=abs(a[1]-a[3])%b[1]
z=abs(abs(a[0]-a[2])/b[0]-abs(a[1]-a[3])/b[1])%2
if x==0 and y==0 and z==0:
    print("YES")
else:
    print("NO")