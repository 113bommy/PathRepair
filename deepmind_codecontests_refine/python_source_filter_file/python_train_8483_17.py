socks=input()
a,b=[int(i) for i in socks.split()]
if a>b:
    more=a
    less=b
else:
    more=b
    less=a

dif=more-less
if dif%2==0:
    same=dif//2
else:
    if dif==1:
        same=0
    else:
        same=dif//2-1

print(less,same)
