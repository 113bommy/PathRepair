n = int(input())

for i in range(1, 11):
    x = n + i
    if '8' in str(x):
        print(i)
        break