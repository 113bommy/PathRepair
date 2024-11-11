
n = int(input())

if n>=-128 and n<=127:
    print("byte")
else:
    if n>=-32768 and n<=32767:
        print("short")
    else:
        if n>=-2147483648 and n<=2147483647:
            print("int")
        else:
            if n>=-9223372036854775808  and n<=92233720368547758087:
                print("long")
            else:
                print("BigInteger")
