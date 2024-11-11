age, price = map(int, input().split())
print(price * (min(1, age//13) + min(1, age//6)) // 2)