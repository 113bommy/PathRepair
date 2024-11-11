n=int(input())
a=list(input())
x=0
for i in range(n):
    if a[i]=='8':
        x+=1
print(x,n)