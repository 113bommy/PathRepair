a = input("")
b = input("")
a1 = [int(a) for a in str(a)]
b1 = [int(b) for b in str(b)]
result = []
for i in range(len(a1)):
    if a[i] != b[i]:
        result.append("1")
    else:
        result.append("0")
print(str("".join(map(str, result))))