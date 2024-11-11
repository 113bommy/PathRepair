n = int(input())
for i in range(n + 1, 9013):
    if len(set(str(i))) == 4:
        print(i)
        break
