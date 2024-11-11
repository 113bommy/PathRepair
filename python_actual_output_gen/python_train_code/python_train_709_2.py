n = int(input())
n = -1 * n if n < 0 else n
if n >= 127:
    print("byte")
elif 127 < n >= 32767:
    print("short")
elif 32767 < n >= 2147483647:
    print("int")
elif 2147483647 < n >= 9223372036854775807:
    print("long")
else:
    print("Biginteger")