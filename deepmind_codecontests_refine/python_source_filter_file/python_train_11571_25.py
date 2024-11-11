a,b=map(int,input().split())
x=b-a
if(b>a):
    print(a)
else:
    print(int(a+(x*(x+1)/2)-1))
