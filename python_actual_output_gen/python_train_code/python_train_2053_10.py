def checker(n, g, b):
    ws = n // 2 + n % 2
    count1 = ws // g
    if ws % g == 0:
        count1 += 1
    count2 = max(count1, 0)
    wb = b * count2
    return ws + wb if n <= ws + wb else n


for _ in range(int(input())):
    N, G, B = [int(i) for i in input().split()]
    print(checker(N, G, B))
