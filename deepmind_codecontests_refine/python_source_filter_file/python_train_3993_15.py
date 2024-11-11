n,m,a=map(int,input().split())
if(m%a==0):
    val1=m//a
else:
    val1=(m//a)+1
if(m%a==0):
    val2= n//a
else:
    val2=(n//a)+1
print(val1*val2)