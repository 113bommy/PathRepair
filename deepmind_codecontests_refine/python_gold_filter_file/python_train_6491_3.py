p,d=[int(x) for x in input().split()]
pow=1
i=0
price=p
while(d>=p%(10**pow)+1):
    if(str(price)[::-1][i]!="9"):
        price=p-p%(10**pow)-1
    i+=1
    pow+=1
print(price)