n = int(input())

for i in range(1, 11):
    if '8' in str(n + i):
        print(i)
        break