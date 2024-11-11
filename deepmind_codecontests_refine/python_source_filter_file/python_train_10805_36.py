N = int(input())
A = [[x - 1 for x in list(map(int, input().split()))] for i in range(N)]

days = 0
cand = set(range(N))

while True:
    games = set() # その日に試合ができるプレイヤーの集合
    
    for p in cand:
        if A[p] != []:
            if A[ A[p][0] ][0] == p:
                games.add(p)
                games.add(A[p][0])
    
    if not games: # その日の試合が開催されない
        if any(A): # 未だ組み合わせ希望が残っている
            print(-1) # 大会の組み合わせ希望は実現不可能
            break
        else: # 大会が終了
            print(days)
            break
    else: #その日の試合が開催された
        for i in games:
            A[i].pop(0) # 大会の組み合わせ希望から、該当する試合を取り除く

    days += 1
    # cand = games # 前日試合をした選手の中から、その日試合する選手を選択