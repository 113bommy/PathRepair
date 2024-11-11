n,a,b = (int(i) for i in input().split())
x=max(a,b)
y=a+b-n
if y < 0:
    y=0
print(x,y)