_,a=open(0)
*a,=map(int,a.split())
d=1
for i in a:d|=d<<i
s=sum(a)//2
print(bin(d)[~s::-1].find('1')+s)