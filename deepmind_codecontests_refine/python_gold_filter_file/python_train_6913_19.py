k,d=map(int,input().split())
if d==0 and k==1:
    print(0)
elif d>0:
    print(d*(10**(k-1)))
else:
    print("No solution")         
