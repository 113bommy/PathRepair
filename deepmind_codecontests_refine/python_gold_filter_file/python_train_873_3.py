n, k = list(map(int, input().split(' ')))

good_numbers = 0
for _ in range(n):
    is_good_number = True
    arr = list(map(int, list(input())))
    if k == 0:
        if 0 not in arr:
            is_good_number = False
    else:
        for i in range(k + 1):
            if i not in arr:
                is_good_number = False
                break
    if is_good_number:
        good_numbers += 1

print(good_numbers)
