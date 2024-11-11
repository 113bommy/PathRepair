ruble = int(input())
dollar_price = int(input())
euro_price = int(input()) * 5

if ruble < dollar_price and ruble < euro_price:
    print(ruble)
else:
    if dollar_price < euro_price:
        smaller_price = dollar_price
        bigger_price = euro_price
    else:
        smaller_price = euro_price
        bigger_price = dollar_price
    left_ruble = ruble - (ruble//smaller_price) * smaller_price
    min_val = left_ruble
    for i in range(ruble//smaller_price+1):
        left_ruble += smaller_price
        tmp = left_ruble // bigger_price
        left_ruble -= bigger_price * tmp
        if left_ruble < min_val:
            min_val = left_ruble
    print(min_val)