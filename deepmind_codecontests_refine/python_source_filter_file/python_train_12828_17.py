t = int(input())
for __ in range(t):
    n, x, y = map(int, input().split())
    best_rank = max(x+y - n + 1, 1)
    worst_rank = min(x+y - 1, n)
    print(best_rank, worst_rank)

# 6 3 4

# best case scenario for test case 2, rank 2 (maximize number of people that has the total of more than current rank)
# 3 4
# 1 1
# 2 6
# 4 5
# 5 3
# 6 2

# worst case scenario for test case 2, rank 6 (maximize number of people that has the total of less than or equal to current rank)
# 3 4
# 1 6
# 2 5
# 4 3
# 5 2
# 6 1

# 1   2   3   4   5   6
# .   /   .   .   .   .
# 6   5   4   3   2   1

# 10 7 6

# 1   2
# 2   1
# 3   3
# 4   4
# 5   5
# 6   6


# best_rank = max(sum - n + 1, 1)
# worst_rank = min(rank1+rank2-1, n)


# 1   
# 2
# 3   3
# 4   
# 5   
# 6   

# 1   5
# 2   4
# 3   2 = 5
# 4   6
# 5   3
# 6   1


# 1   1
# 2   6
# 3   4
# 4   5
# 5   3
# 6   2

# 1   1
# 2   2
# 3   5 = 8
# 4   6
# 5   4
# 6   3

# best
# sum - n -- minimal org yg lbh kecil nilai atau sama dengan dia
# sum -n + 1 --> best rank
# maximize number of people that has the total of strictly more than current rank ~ minimize number of people that has the total of not more than current rank