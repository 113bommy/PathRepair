a, b, c = input(), input(), input()
d = {}
for char in c:
    for i in range(0,len(a)):
        if a[i] == char.lower():
            d[char.lower()] = i
            break
ans = ""
for char in c:
    if char.isdigit():
        ans += char
    elif char.isalpha() == True:
        ans += b[d[char.lower()]].upper()
    else:
        ans += b[char]
print(ans)
