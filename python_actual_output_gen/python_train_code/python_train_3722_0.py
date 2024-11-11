for id in range(21, 51):
    if ((min(id, 25) + id) % (2 + id % 3)) > 0:
        print('YES')
    else:
        print('NO')
