k=int(input())
a=''
if k==0:
    a=a+'0'
if k>0:
    while k!=0:
        a=str(k%8)+a
        k=k//8
if k<0:
    k=-1*k
    a=a+'-'
    while k!=0:
        a=str(k%8)+a
        k=k//8
m=0
for i in range(len(a)):
    if a[i]==0:
        m=m+1
print(m)
