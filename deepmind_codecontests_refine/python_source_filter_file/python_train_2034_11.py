def main():
    n = input()
    n = int(n)
    if n >= -127 and n <= 127:
        print("byte")
    elif n >= -32768 and n <= 32767 :
        print("short")
    elif n >= -2147483648 and n <= 2147483647:
        print("intger")
    elif n >= -9223372036854775808 and n <= 9223372036854775807:
        print("long")
    else:
        print("BigInteger")
    





main()
