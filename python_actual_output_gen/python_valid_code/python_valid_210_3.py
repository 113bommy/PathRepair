n=int(input())
a=[]
x=1
for i in range(1,n):
    x+=i
    if x%n==0:
        a.append(1)
    else:
        a.append(x%n)
print(*a)