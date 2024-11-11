a = int(input())
for i in range(a, 1003):
    if sum(list(map(int, list(str(i))))) % 4 == 0:
        print(i)
        exit()
