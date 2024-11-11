M=2019
a=i=0
d=[0]*M
p=1
for j in input()[::-1]:d[i%M]+=1;i-=int(j)*p;a+=d[i%M];p*=10
print(a)