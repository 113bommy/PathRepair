n=int(input())
a=range(-128,128)
b=range(-32768,327678)
c=range(-2147483648,2147483648)
d=range(-9223372036854775808,9223372036854775808)

if n in a:
    print("byte")
elif n in b:
    print("short")
elif n in c:
    print("int")
elif n in d:
    print("long")
elif n not in d:
    print("BigInteger")
