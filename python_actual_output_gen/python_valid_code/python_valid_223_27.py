n = int(input())
for i in range(n + 1, 4):
    if (n - i) % 7 == 0:
        print('Yes')
        exit()
print('No')