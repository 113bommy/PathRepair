n = int(input())
for i in range(n + 1, 9013):
    if len(set(list(str(i)))) == 4:
        print(i)
        exit()

