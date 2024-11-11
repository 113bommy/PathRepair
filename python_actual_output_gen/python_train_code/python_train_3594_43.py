insert=input()
x=insert.split()
banana_price=int(x[0])
money=int(x[1])
banana_he_wants=int(x[2])
sum=0


for each in range(banana_he_wants):
    n=(each+1)*banana_price
    sum+=n

if sum > money:
    print(sum-money)
else:
    print()
