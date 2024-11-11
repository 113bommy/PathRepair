t = int(input())

for _ in range(t):
    n = int(input())
    numbers = [int(x) for x in input().split()]

    odd_count = 0
    even_count = 0
    for i in range(n):
        if numbers[i] % 2:
            odd_count += 1
        else:
            even_count += 1
    
    condition_1 = abs(odd_count - even_count) <= 1
    condition_12 = odd_count % 2 == 0 and even_count + 1 == odd_count
    condition_13 = odd_count % 2 and odd_count + 1 == even_count
    condition_2 = (n % 2 and (condition_12 or condition_13) and even_count > 0) or (n % 2 == 0 and odd_count == even_count)

    if condition_1 and condition_2:
        count = 0
        for i in range(n - 1):
            for j in range(i + 1, n):
                if numbers[j] % 2 == i % 2 and numbers[i] % 2 != i % 2 and numbers[j] % 2 != j % 2:
                    numbers[j], numbers[i] = numbers[i], numbers[j]
                    count += 1
        print(count)
    else:
        print(-1)