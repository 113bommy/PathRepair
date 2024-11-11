t=int(input())
while(t):
    n=int(input())
    l=[]
    s=0
    k=n//2
    for i in range(k):
        l.append(8*(i+1))
    for i,j in zip(range(k),range(k,0,-1)):
        s+=l[i]*j
    print(s)
    t-=1