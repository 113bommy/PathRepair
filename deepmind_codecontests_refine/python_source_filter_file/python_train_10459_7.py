a, b = list(map(int, input().split()))

if a < b:
    print(0)
elif a == b:
    print('infinity')
else: 
    num = a - b
    limit = int(num ** 0.5)
    divisors = 0

    for i in range(1, limit + 1):
        if num % i == 0:
            divisors += 1
            if i < b or i == num // i:
                divisors -=1
            if num//i > b:
                divisors += 1


    print(divisors)