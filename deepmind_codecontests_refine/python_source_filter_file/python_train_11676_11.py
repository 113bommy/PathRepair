def function(x):
    x += 1
    while x % 10 == 0:
        x //= 10
    return x


x = int(input())
i = 9
while x > 10:
    x = function(x)
    i += 1
print(i)
