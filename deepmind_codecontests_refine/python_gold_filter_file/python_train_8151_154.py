n, k, l, c, d, p, nl, np = map(int, input().split())
drink_toast = (k * l)//nl
lime_toast = c * d
salt_toast = p // np
print(min(drink_toast, lime_toast, salt_toast) // n)