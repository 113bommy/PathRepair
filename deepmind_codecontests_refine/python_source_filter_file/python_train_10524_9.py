x=int(input())
a=[]
sum=0
sum1=0
for i in range(1,x+1):
    p,q,r,s=map(int,input().split())
    sum=p+q+r+s
    if i==1:
        sum1=sum
    a.append(sum)
a.sort(reverse=True)
d=a.index(sum1)+1
print(a)
print(d)
