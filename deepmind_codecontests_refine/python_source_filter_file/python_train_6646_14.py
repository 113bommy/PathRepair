from collections import Counter

def update_rank_lis(rank_lis, drop_sport):
    return [
        [sport for sport in ranks if sport != drop_sport]
        for ranks in rank_lis
    ]

def count_first(rank_lis):
    first_cnt = Counter([ranks[0] for ranks in rank_lis])
    return sorted([(cnt, sport) for sport, cnt in first_cnt.items()])[-1]

def solve(N, M, rank_lis):
    min_value = M
    for _ in range(M):
        most_pop_cnt, most_pop_sport = count_first(rank_lis)
        min_value = min(most_pop_cnt, min_value)
        rank_lis = update_rank_lis(rank_lis, most_pop_sport)
    print(min_value)
    
N, M = map(int, input().split())
rank_lis = [list(map(int, input().split())) for _ in range(N)]
solve(N, M, rank_lis)