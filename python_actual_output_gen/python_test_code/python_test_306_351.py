m, n = map(int, input().split())

area = m * n

if area % 2 == 0:
    print(f"luck\n{int(area/2)}")
else:
    print(f"{int(area/2)}")
