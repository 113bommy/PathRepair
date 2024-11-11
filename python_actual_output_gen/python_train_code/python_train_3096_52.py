a = int(input()[-1])

s = [pow(x, a) for x in range(1, 5)]
print(sum(s) % 5)
