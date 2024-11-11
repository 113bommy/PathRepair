x = int(input())
for i in range(x):
    a, b, c, d = map(int, input().split())
    if a == 0 and d == 0:
        if b % 2 == 1:
            print("Tidak Ya Tidak Tidak")
        else:
            print("Tidak Tidak Ya Tidak")
    elif b == 0 and c == 0:
        if a % 2 == 1:
            print("Ya Tidak Tidak Tidak")
        else:
            print("Tidak Tidak Tidak Ya")
    else:
        if (a+b) % 2 == 1:
            print("Ya Ya Tidak Tidak")
        else:
            print("Tidak Tidak Ya Ya")

