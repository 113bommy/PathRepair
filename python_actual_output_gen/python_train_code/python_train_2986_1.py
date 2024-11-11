res=[]
for x in range(int(input())):
    a,b,c=map(int,input().split())
    Reqsticks=c*b
    i=((Reqsticks)//(a-1)+((Reqsticks)%(a - 1)>0))
    total=i+c
    res.append(total)
for c in res:
    print(c) 