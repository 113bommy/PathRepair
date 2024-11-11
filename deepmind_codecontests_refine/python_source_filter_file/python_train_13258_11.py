a=input()
n=int(a.split()[1])
s=int(a.split()[0])
x=[]
b=0
for i in range(0,n):
    a=input().split()
    x.append((int(a[0]),int(a[1])))
x=sorted(x)
print(x)
for i in range(0,n):
    if s>x[i][0]:
        s+=x[i][1]
        b+=1
if b<n:
    print("NO")
else:
    print("YES")
    
