n=int(input())
ls=list(map(int,input().split()))
t=sum(ls)-2*sum(ls[1::2])
x=[t]
for i in ls:
    t=i*2-t
    x.append(t)
x.pop()
print(*x)
