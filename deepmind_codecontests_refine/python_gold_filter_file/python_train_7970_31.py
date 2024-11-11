n,k=map(int,input().split())
x=240-k
c=0
i=1
while x-(5*i)>=0 and n>0:
    # print(i,x)
    x-=5*i
    i+=1
    c+=1
    n-=1
print(c)