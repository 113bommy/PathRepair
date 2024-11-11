n, m, k = tuple(map(int, input().split()))
f1, f2 = 0, 0
numbers = list(map(int, input().split()))
for number in numbers:
    if number >= f1:
        f2 = f1
        f1 = number
    elif number >= f2:
        f2 = number
iteration = m // k+1
reminder = m - (k+1)*iteration
print((k*f1+f2)*iteration+reminder*f1)