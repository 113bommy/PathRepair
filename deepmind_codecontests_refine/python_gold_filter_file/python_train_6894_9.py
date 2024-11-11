def I(): return map(int, input().split())


for _ in range(int(input())):
    n, m = I()
    print("YNEOS"[(n % m) != 0::2])
