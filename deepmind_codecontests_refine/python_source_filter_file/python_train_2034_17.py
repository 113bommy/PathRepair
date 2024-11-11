n=int(input())

if n in range(-128,128):
    print("byte")
elif n in range(-32768,32768):
    print("short")
elif n in range(-2147483648,2147483649):
    print("int")
elif n in range(-9223372036854775808,9223372036854775808):
    print("long")
else:
    print("BigInteger")
