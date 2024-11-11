start = int(input())
x = start ** .5
x = int(x)
total = x * 2
temp = x ** 2
extra = (start - temp)/x
if(extra % 1 != 0):
    total += int(extra) + 1
else:
    total += extra
print(total)
