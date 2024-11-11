n = int(input())
a = []
for four in range(n // 4 + 1):
    for seven in range((n - four * 4) // 7 + 1):
        if four * 4 + seven * 7 == n:
            a = [4] * four + [7] * seven
            for i in a:
                print(i, end='')
            exit()
print(-1)