byte = [-128, 127]
short = [-32768, 32767]
int_type = [2147483648, 2147483647]
long = [9223372036854775808, 9223372036854775807]
n = int(input())

if byte[0] <= n <= byte[1]:
    print("byte")
elif short[0] <= n <= short[1]:
    print("short")
elif int_type[0] <= n <= int_type[1]:
    print("int")
elif long[0] <= n <= long[1]:
    print("long")
else:
    print("BigInteger")
