k=int(input());x=''
if k>=37:
    print(-1)
elif k%2==0:
    for i in range(0,k//2-1):
        x+='8'
    x+='8'
    print(x)
else:
    for i in range(0,k//2):
        x+='8'
    x+='6'
    print(x)