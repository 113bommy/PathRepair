n = int(input())
price = list(map(int,input().split()))
price.sort(reverse=True)
m = int(input())
coupon = list(map(int,input().split()))
fullmoney = sum(price)

for i in coupon:
    print(fullmoney - price[i - 1])
