number = [int(x) for x in input().split()]

milliliters = number[1] * number[2]
toast_drink = milliliters // number[6]
toast_limes = number[3] * number[4]
toast_salt = number[5] // number[7]

toast = [toast_drink, toast_limes, toast_salt]
result = min(toast) // number[0]
print(result)
