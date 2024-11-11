n,x=map(int,input().split())
cnt=0
for t in range(n):
    a,b=input().split()
    b=int(b)
    if(a=="+"):
        x=x+b
    elif(x-b>0):
        x=x-b
    else:
        cnt+=1
print(x,cnt)