a=int(input())
if a>-129 and a<128:
    print("byte")
elif a>-32769 and a<32768:
    print("short")
elif a>-2147483649 and a<2147483648:
    print("short")    
elif a>-9223372036854775809 and a<9223372036854775808:
    print("long") 
else:
    print("BigInteger")