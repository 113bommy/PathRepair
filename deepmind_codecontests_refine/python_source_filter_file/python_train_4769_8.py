import heapq
Q = int(input())

lefts, rights = [], []  # lefts:aの左半分（中央値含む, 降順） rights:aの右半分
diff = 0    # aの中央値からの差の絶対値
bsum = 0    # bの累計

for i in range(Q):
    query = list(map(int, input().split()))
    if query[0] == 1:   # 更新クエリ(1)の処理
        a = query[1]
        bsum += query[2]
        if len(lefts) == 0:
            heapq.heappush(lefts, -a)   # 最初はleftsに降順に格納（中央値）
        else:
            if a <= -lefts[0]:
                heapq.heappush(lefts, -a)   # 現在の中央値以下ならleftsに降順にpush
                diff -= a + lefts[0]        # 現在の中央値(-lefts[0])との差
            else:
                heapq.heappush(rights, a)   # 現在の中央値より大きいならrightsにpush
                diff += a + lefts[0]        # 現在の中央値(-lefts[0])との差
        # lefts が rights と同数か1多い状態をキープするため、ずれたら移動
        if len(lefts) < len(rights):    # 偶数状態からrightsにpushされ、rightsが1件多い、奇数状態
            med = heapq.heappop(rights) # 新しい中央値をrightsからpop
            diff += med + lefts[0]      # 奇数なので、rightsの1件以外相殺されるから、新中央値と旧中央値の差を加える
            heapq.heappush(lefts, -med) # 新しい中央値をleftsにpush
        elif len(lefts) > len(rights) + 1:  # 奇数状態からleftsにpushされ、leftsが2件多い、偶数状態
            med = -heapq.heappop(lefts)      # これまでの中央値をleftsからpop（-1倍）
            # 偶数なので、中央値がずれても相殺されるから、diffは修正不要
            heapq.heappush(rights, med)     # これまでの中央値をrightsにpush
    else:   # 求値クエリ(2)の処理
        x = -lefts[0]       # 中央値がx
        fx = diff + bsum    # 中央値からの差の絶対値(diff)とbの累計(bsum)の和
        print(x, fx)