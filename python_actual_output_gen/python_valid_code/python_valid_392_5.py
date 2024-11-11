def bintodec(binary):
    b1=binary
    decimal,i,n=0,0,0
    while(binary):
        dec=b1%10
        decimal+=dec*pow(2,i)
        binary//=10
        i+=1
    return decimal
c=0
y=1
bin=int(input())
ans=bintodec(bin)
while(y<ans):
    c+=1
    y*=4
print(c)