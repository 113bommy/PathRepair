a = input()
fl = len(a) // 2 + (len(a) % 2 - 1)
if len(a) <= 1:
    result = a
else:
    result = a[fl]
    for i in range(0, fl):
        result += a[fl + i + 1] + a[fl - i - 1]
        if i == fl - 1 and len(a) % 2 == 0:
            result += a[fl + i + 2]
print(result)
