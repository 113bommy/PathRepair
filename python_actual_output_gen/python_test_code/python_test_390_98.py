n = int(input())

a = [i for i in range(n) if i % 3 != 0 and i % 5 != 0]

print(sum(a))