def nC2(n):
    return n * (n - 1) // 2


if __name__ == "__main__":
    n, m = map(int, input().split())
    # Each team we need at least one participant, so, we remove m from n once.
    # For maximum, we add all the remaining members to one team.
    max_team_count = (n - m) + 1
    # nC2 = n*(n-1)//2
    k_max = nC2(max_team_count)  # Rest all have only one person.
    if m == 1:
        print(k_max, k_max)
        exit(0)
    # For minimum we try to spread out as evenly as possible.
    q, r = divmod(n, m)
    # we first gave q members for all teams
    # now, 1 will be given to r teams to make it more evenly spread.
    count_1 = q + 1
    count_2 = q
    k_min = r * nC2(count_1) + (m - 1) * nC2(count_2)
    print(k_min, k_max)
