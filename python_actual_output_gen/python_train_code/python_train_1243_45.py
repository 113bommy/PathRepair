n,x=map(int,input().split())
l=[]
while(n):
    s,d=map(str,input().split())
    if(s=='-'):
        if(x>int(d)):
            x = x - int(d)
        else:
            l.append(d)
    elif(s=='+'):
        x=x+int(d)
    n=n-1
print(x,len(l))