n=int(input())
x=input()
x=x.split()
a=[]
for i in range(n):
    a.append(int(x[i]))
p=min(a)
count=0
for i in range(n):
    count=count+a[i]-p
print(count)
    