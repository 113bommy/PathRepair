n = int(input())

f_line = input()
f_arr = [int(y) for y in f_line.split()]

worst = f_arr[0]
best = f_arr[0]
count = 0

for i in range(1, n):
    if f_arr[i] < worst:
        count += 1
        worst = f_arr[i]
    elif f_arr[i] > best:
        count += 1
        best = f_arr[i]
    else:
        pass
print(count)
