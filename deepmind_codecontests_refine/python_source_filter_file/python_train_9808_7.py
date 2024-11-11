print([next(map(lambda x : max(0, 2 * (x[2] - x[0] - 2)), 
            [list(sorted(list(map(int, input().split()))))])) for _ in range(int(input())) ], 
    sep = '\n')