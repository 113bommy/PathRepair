x=int(input())
if 128 >= x > -128:
    print("byte")
elif 32768>= x > -32768:
    print("short")
elif 2147483647>= x > -2147483648:
    print("int")
elif 9223372036854775808>= x > -9223372036854775808:
    print("long")
else:
    print("BigInteger")



