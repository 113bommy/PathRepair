X,Y=map(int,input().split())
mod=pow(10,9)+7
m=(2*X-Y)//3
n=(2*Y-X)//3
if  m==(2*X-Y)/3 and n!=(2*Y-X)/3 and m>=0 and n>=0:
    bunsi = 1
    bunbo = 1
    for i in range(0, n):
        bunsi = (bunsi * (m + 1 + i)) % mod
        bunbo = (bunbo * (1 + i)) % mod
    print((bunsi * pow(bunbo, mod - 2, mod)) % mod)

else:
    print(0)