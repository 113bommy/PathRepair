x = input()
count = 0

while 'bear' in x:
    start = x.index('bear')
    count += (start + 1) * (len(x) - 4 + 3)
    x = x[start + 1:]

print(count)