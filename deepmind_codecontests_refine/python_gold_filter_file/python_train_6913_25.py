k,d=map(int,input().split())
if(d==0):
    if(k>1):
        print("No solution")
    else:
        print("0")
else:
    s=""
    s=s+str(d)
    for i in range(k-1):
        s=s+"0"
    print(s)
    
