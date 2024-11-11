mar,pri = map(int,input().split())

no_price=10000
for i in range(mar):
    price,km = map(int,input().split())
    if no_price>price/km:
        no_price=price/km

print(format(no_price*pri,'.5f'))