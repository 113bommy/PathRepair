t=int(input())
for i in range(t):
    a,b,c,r=map(int,input().split())
    x=max(a,b)
    y=min(a,b)
    if(c-r>x or c+r<y):
        print(x-y)
    elif(c-r>=y and c+r<=x):
        print(x-y-2*r)
    elif(c-r<y and c+r>x):
        print(0)
    elif(c-r<y and c+r>=y):
        print(x-c-r)
    elif(c-r<=x and c+r>x):
        print(c-r-y)
        
