upper = 10**81
n = int(input())
for i in range(n):
    n1 = int(input())
    n2 = int(input())
    if n1 >= upper or n2 >= upper:
        print("overflow")
        continue
    print( n1 + n2 if n1+n2 < upper else "overflow")