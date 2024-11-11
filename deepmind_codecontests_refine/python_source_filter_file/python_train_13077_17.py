a,b = [int(i) for i in input().split()]
product = 1
if b-a>=4:
    print(0)
else:
    for x in range(b,a,-1):
        if str(x)[-1]==0:
            product = 0
            break
        product*=x
        product = int(str(product)[-1])
    print(product)
