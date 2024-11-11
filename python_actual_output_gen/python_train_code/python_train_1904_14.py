M = int(input())
DC = [list(map(int, input().split())) for _ in range(M)]

digits_sum = 0
digits_length = 0
for d, c in DC:
    digits_sum += d*c
    digits_length += c

# print(digits_sum, digits_length)

print((digits_length - 1) + (digits_sum // 9))
