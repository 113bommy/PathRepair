from math import ceil

n=int(input())
k=0
count=0

j=0
for i in range(n):
        k+=5*(2**i)
        if k>n:
                j=i
                b=k-5*(2**i)
                break
m=n-b
p=ceil(m/(2**i))
#print(p)
if p==1:
        print('Sheldon')
if p==2:
        print('Leonard')
if p==3:
        print('Penny')
if p==4:
        print('Rajesh')
if p==0:
        print('Howard')
