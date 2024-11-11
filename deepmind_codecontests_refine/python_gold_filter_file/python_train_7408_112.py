def func(n):
    if n%2!=0:
        return 0
    else:
        return int(2**(n/2)) 
number = int(input())
print(func(number))