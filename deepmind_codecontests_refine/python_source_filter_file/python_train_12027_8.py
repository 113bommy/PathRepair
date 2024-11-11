n = int(input())
answ = 1
for x in range(n, n - 4, -1):
    answ *= x;
print(answ ** 2 // 120)