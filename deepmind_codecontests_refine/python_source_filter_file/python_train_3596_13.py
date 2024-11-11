inp=input().split()
q=False
while q==False:
    try:
        n=int(inp[0])
        x=int(inp[1])
        q=True
    except:
        inp=input().split()
        q=False
c=0
if (n>=1 or n<=1000) & (x>=0 or x<=10**9) :
    for p in range(0, n):
        in2=input().split()
        q=False
        while q==False:
            try:
                log=str(in2[0])
                d=int(in2[1])
                q=True
            except:
                in2=input().split()
                q=False
        if log=="+":
            x=x+d
        elif log=="-":
            if x>d: x=x-d
            else: c+=1
        else: pass
print(x," ",c)