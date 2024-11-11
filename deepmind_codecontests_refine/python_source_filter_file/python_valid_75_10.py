from sys import stdin
from collections import defaultdict

input = stdin.buffer.readline


def func():
    keys = list(game.keys())

    ans = defaultdict(list)
    for key in keys:
        for cave in game[key]:
            start = 0
            wins = 0
            begin = 0
            for enemy in cave:
                # print('Before', begin, start, enemy)
                if start <= enemy:
                    # begin += enemy+1-start
                    start = enemy + 1

                # print('After', begin, start, enemy)
                begin = start - wins
                wins += 1
                start += 1
            ans[begin].append(wins)

    # print(ans)
    k = list(ans)
    k.sort()
    # print(k)
    lol = k[0]
    haha = lol
    wins = 0
    for i in k:
        for j in ans[i]:
            if lol < i:
                # haha += i+1-lol
                lol = i+1

            haha = lol - wins
            wins += j
            lol += j

    print(haha)


for _ in range(int(input())):
    n = int(input())
    game = defaultdict(list)
    for __ in range(n):
        lst = list(map(int, input().split()))[1:]
        # lst.sort()
        game[max(lst)].append(lst)
    # print(game)
    func()

# 1
# 3
# 5 3 2 4 1 7
# 4 3 4 5 2
# 4 6 7 3 2