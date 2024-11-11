import itertools

N, K = map(int, input().split()) # Nは建物の数、K色以上に塗る
A = list(map(int, input().split()))
N_index = list(range(1,N))

min_cost = float('inf')
for target_indexes in itertools.combinations(N_index, K-1): # N_indexからK個選ぶ方法を全通り試す
    cost = 0
    copy_A = A.copy()
    for i in range(1, N):
        if i in target_indexes:
            if copy_A[i] <= max(copy_A[:i]):
                diff = max(copy_A[:i]) - copy_A[i] # ターゲットの建物の場合はそれより左側の建物のmaxより1だけ大きくする
                copy_A[i] += diff + 1
                cost += diff + 1

    min_cost = min(min_cost, cost)

print(min_cost)
