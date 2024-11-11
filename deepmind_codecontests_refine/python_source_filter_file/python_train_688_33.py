n=int(input())
f1=1
f2=1
x=[f1,f2,2]
name=""
for i in range(3,n):
    x.append(x[i-2]+x[i-1])
for j in range(n) :
    if ((j+1) in x):
        name=name+"O"
    else:
        name=name+"o"
print(name)