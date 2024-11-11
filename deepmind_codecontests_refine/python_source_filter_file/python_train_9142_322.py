n = int(input())
print(len(list(set(map(int, input() for i in range(n))))))