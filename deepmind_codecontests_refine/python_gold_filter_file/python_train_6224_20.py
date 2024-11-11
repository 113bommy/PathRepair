M,a,t,p=2019,0,0,1
l=[0]*M
for i in input()[::-1]:l[t]+=1;t=(t+int(i)*p)%M;a+=l[t];p=p*10%M
print(a)