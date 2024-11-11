# D
A, B = map(int, input().split())
res_list = [["."]*100 for _ in range(20)] + [["#"]*100 for _ in range(20)]
A -= 1
B -= 1
for i in range(0, 20, 2):
    for j in range(0, 100, 2):
        if B > 0:
            res_list[i][j] = "#"
            B -= 1
for i in range(21, 40, 2):
    for j in range(0, 100, 2):
        if A > 0:
            res_list[i][j] = "."
            A -= 1
print("40 100")
for res in res_list:
    print("".join(res))