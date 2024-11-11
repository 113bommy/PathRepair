k,d=map(int,input().split())
if d==0 and k>1:
    print("No Solution")
else:
    x=str(d)+"0"*(k-1)
    print(x)