x=int(input())
y=list(map(int,input().split()))
z=list(map(int,input().split()))
f=0
for i in range(z[1]-1):f+=y[i]
print(f)

