input();a=b=c=0;p=1;m=10**9+7
for i in input():
    if i=='a':a+=p
    elif i=='b':b+=a
    elif i=='c':c+=b
    else:a,b,c,p=(a*3+p)%m,(b*3+a)%m,(c*3+b)%m,(p*3)%m
print(c)