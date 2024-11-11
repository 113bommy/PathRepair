X,Y=map(int,input().split())
mod=pow(10,9)+7
m=(2*X-Y)//3
n=(2*Y-X)//3
if  m!=(2*X-Y)/3 or n!=(2*Y-X)/3 or m<=0 or n<=0:
    print(0)

else:
    bunsi = 1
    bunbo = 1
    for i in range(0, n):
        bunsi = (bunsi * (m + 1 + i)) % mod
        bunbo = (bunbo * (1 + i)) % mod
    print((bunsi * pow(bunbo, mod - 2, mod)) % mod)