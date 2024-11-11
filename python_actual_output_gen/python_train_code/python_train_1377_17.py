def answer(a,b,c):
    l=[]
    for i in range(1,73):
        x=b*((i)**a)+c
        count=0
        t=x
        while t>0:
            count+=t%10
            t=t//10
        
        if count==i and x<10**9:
            l.append(x)
    return l

a,b,c=map(int,input().split())
ans=answer(a,b,c)
print(len(ans))
print(*ans)