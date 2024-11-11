a,b,c=input().strip().split(' ')
a,b,c=(int(a),int(b),int(c))
m=max(a,b,c)
if a==b and b==c:
    print(0)
    exit()
if a==m and b<a and c<a:
    print(2*a-2-b-c)
elif b==m and b>c:
    if a<b:
        print(b-1+b-1-a-c)
    elif a==b:
        print(2*b-a-c)
elif m==c:
    if a<c and b<c:
        print(c+c-2-a-b)
    elif a==c and b<c:
        print(c-1-b)
    elif a<c and b==c:
        print(c-1-a)
         