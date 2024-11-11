l=list(map(int,input().split()))
n=l[0]
m=l[1]
a=l[2]
b=l[3]
print(a,b)
for i in range(2,b):
    print(a,i)
for i in range(b+1,m+1):
    print(a,i)
print(a,1)

for i in range(1,a):
    if i%2==1:
        for j in range(1,m+1):
            print(i,j)
    else:
        for j in range(m,0,-1):
            print(i,j)

for i in range(a+1,n+1):
    if i%2==0:
        for j in range(1,m+1):
            print(i,j)
    else:
        for j in range(m,0,-1):
            print(i,j)



