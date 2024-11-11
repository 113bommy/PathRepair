n = int(input())

results = []
for i in range(n):
    m = int(input())
    results.append([i for i in range(m, 0, -1)])

for result in results:
    print(len(result))
    for value in result:
        print(value, end=' ')
    print()
