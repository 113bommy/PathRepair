t=int(input())
for i in range(t):
    n,x,a,b=input().split()
    n,x,a,b=int(n),int(x),int(a),int(b)
    if n>=x+abs(a-b):
        print(x+abs(a-b))
    else:
        print(n-1)

