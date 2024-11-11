def temp(a, b):
    res = 0
    for j in range(b):
        res += a
    return res


n, k, l, c, d, p, nl, np = map(int, input().split())
count = 0
drink = n*nl
drink1 = drink
lime = 1
lime1 = lime
salt = n*np
salt1 = salt
i = 2
while True:
    if drink1 <= k*l and lime1 <= c*d and salt1 <= p:
        count += 1
        drink1 = temp(drink, i)
        lime1 = temp(lime, i)
        salt1 = temp(salt, i)
        i += 1
        #print(drink1, lime1, salt1)
    else:
        break
print(count)


