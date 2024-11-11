NULL = 10000
TOWN_COUNT = 10

while True:

    input_count = int(input())

    if input_count == 0:
        break

    adjacency_matrix = [[NULL] * TOWN_COUNT for _ in range(TOWN_COUNT)]

    for lp in range(TOWN_COUNT):
        adjacency_matrix[lp][lp] = 0

    need_range = 0

    for _ in range(input_count):
        start, end, time = [int(item) for item in input().split(" ")]

        adjacency_matrix[start][end] = time
        adjacency_matrix[end][start] = time

        need_range = max(need_range, start, end)

    for a in range(need_range + 1):
        for b in range(need_range + 1):
            for c in range(need_range + 1):
                adjacency_matrix[a][c] = min(adjacency_matrix[a][b] + adjacency_matrix[b][c], adjacency_matrix[a][c])

    min_time = NULL
    min_index = -1

    for index, item in enumerate(adjacency_matrix):
        need_element = [item2 for item2 in item if 0 < item2 < NULL]

        if 0 < len(need_element):
            time = sum(need_element)

            if time < min_time:
                min_time = time
                min_index = index

    print(min_index, min_time)

