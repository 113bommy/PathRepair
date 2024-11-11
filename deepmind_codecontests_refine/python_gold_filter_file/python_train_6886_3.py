from math import log, ceil
base = int(input())
power = int(input())
a = round(log(power)/log(base))
print('YES\n' + str(a-1) if base**a == power else 'NO')