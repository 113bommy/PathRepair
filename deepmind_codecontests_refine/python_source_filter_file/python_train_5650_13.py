import math

t = int(input())

for _ in range(t):

    n = int(input())

    a_vec = input().split(" ")
    a_vec = [int(a) for a in a_vec]
    s = sum(a_vec)
    mp = max(a_vec)

    if( mp > math.floor(s / 2.0) or (mp < math.floor(s / 2.0) and s % 2 != 0) ):
        print("T")
    else:
        print("HL")