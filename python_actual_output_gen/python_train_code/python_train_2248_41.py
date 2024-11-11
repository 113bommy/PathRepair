n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
previous_n = 1
s = 0
for e in a:
    if previous_n >= e:
        s += e + n - previous_n
    else:
        s += e - previous_n
    previous_n = e
print(s)