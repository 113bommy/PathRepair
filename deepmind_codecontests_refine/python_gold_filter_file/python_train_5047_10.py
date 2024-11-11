n = input().split()
a = int(n[0])
b = int(n[1])
count = 0
while (not ((a == b) or (a == 0) or (b == 0))):
    if (a > b):
        x = int(a / b)
        a -= x * b
    else:
        x = int(b / a)
        b -= x * a
    count += x
print(count)