n = int(input())
m = int(input())

if n > 64:
    print(m)
else:
    print(m % pow(2,n))