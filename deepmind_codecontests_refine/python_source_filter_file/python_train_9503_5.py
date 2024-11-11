def fact(n):
    if n<=1:
        return 1
    return fact(n-1)


x=int(input())
print(2*fact(x-1)/x)