k=0
t,i=map(int,input().split())
for _ in range(t):
    s,c=input().split()
    c=int(c)
    if s=="+":
        i+=c
    elif c >= i:
        i-=c
    else:
        k+=1
print(i,k)