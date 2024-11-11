input()
l=list(map(int,input().split()))
a=max(l[0:2])
b=min(l[0:2])
x=int(a!=b)
for i in range(2,len(l)):
    if l[i]>a :
            x+=1
            a=l[i]
    if l[i]<b:
            x+=1
            b=l[i]
print(x)