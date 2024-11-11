import math

for _ in range(int(input())):
    d, k = map(int, input().split())
    outer_x, outer_y = math.floor(math.sqrt((d ** 2) / 2)) // k * k,  math.floor(math.sqrt((d ** 2) / 2)) // k * k
    if math.sqrt((outer_x + k) ** 2 + outer_y ** 2) < d:
        print("Ashish")
    else:
        print("Utkarsh")
