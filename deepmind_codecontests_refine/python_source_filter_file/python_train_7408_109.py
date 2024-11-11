def func(n):
    if n%2!=0:
        return 0
    else:
        return 2**n 
number = int(input())
print(func(number))