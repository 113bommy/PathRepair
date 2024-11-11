a = int(input()[-2:])

s = [pow(x, a) for x in range(1, 5)]
print(sum(s) % 5)
