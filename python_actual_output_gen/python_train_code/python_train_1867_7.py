t=int(input())
low=1
high=t
res=0
while low<=high:
    if low%high==0 and high%low==0:
        res+=1
    low+=1
    high-=1
print(res)