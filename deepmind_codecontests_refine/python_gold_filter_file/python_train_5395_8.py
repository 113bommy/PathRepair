n = int(input())
lst = [105, 135, 165, 189, 195, 201]
for i in range(6):
    if n < lst[i]:
        print(i)
        break