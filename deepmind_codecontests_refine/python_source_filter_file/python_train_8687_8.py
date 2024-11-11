input_lst = input().split()
n = int(input_lst[0])
m = int(input_lst[1])
k = int(input_lst[2])

players = []

for i in range(m):
    players.append(int(input()))

you = int(input())
result = 0
for player in players:
    tmp_you = you
    count = 0
    for i in range(n):
        if tmp_you % 2 == player % 2:
            count += 1
        tmp_you /= 2
        player /= 2

    if n - count <= k:
        result += 1

print(result)