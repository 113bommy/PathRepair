k=int(input())
start=1
el=0
num=[]
while el!=k:
    li=list(str(start))
    li=list(map(int,li))
    s=sum(li)
    n=len(li)
    pos=0
    if s>10:
       while sum(li[0:n-1]) >=9:
           n-=1
           pos+=1
       ans=int(''.join(map(str,li[0:n])))
       start=(ans+1)*(10**pos)
    else:
        num.append(str(start)+str(10-s))
        start+=1
        el+=1
print(num[k-1])

