value = input()

trailingZero = len(value) - len(value.rstrip('0'))
pal = trailingZero*'0' + value

if value == value[::-1]:
    print("YES")
elif pal == value:
    print("YES")
else:
    print("NO")