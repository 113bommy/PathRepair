def fact(int1):
    if(int1 == 0):
        return 1
    else:
        return int1 * fact(int1-1)

x = int(input(""))
x = 2*(x - 1)
y = x//2
a = x - y

print((fact(x))/((fact(y))*(fact(a))))