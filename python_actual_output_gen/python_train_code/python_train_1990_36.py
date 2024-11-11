n=int(input())
for i in range(n,1002):
    s=list(str(i))
    s=map(int,s)
    su=sum(s)
    if su%4==0:
        print(i)
        break
