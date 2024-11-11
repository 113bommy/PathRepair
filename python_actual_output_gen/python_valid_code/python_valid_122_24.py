n=int(input())
z=[]
for i in range(n):
    y=int(input())
    x=str(input())
    a=int(x[0])
    b=(x[1:n])
    b=int(b)
    if a<b:
        print("YES")
        print(2)
        print(a,b)
    else:
        print("NO")