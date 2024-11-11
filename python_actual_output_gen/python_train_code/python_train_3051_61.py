x=int(input())
for i in range(x):
    a,b,c,d=[int(t) for t in input().split()]
    d=min(a+b,c+d)
    print(d)
 
