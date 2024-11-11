k, n, m = [int(x) for x in input().split()]

plate = [[[0 for z in range(k)] for y in range(m)] for x in range(n)]

for k_index in range(k):
    input()
    for n_index in range(n):
        line = input().strip()
        for m_index in range(m):
            plate[n_index][m_index][k_index] = line[m_index]

DIRS = [(-1, 0, 0), (1, 0, 0), (0, -1, 0), (0, 1, 0), (0, 0, -1), (0, 0, 1)]
total = 0

def check_legal(n_index, m_index, k_index):
    if n_index < 0 or m_index < 0 or k_index < 0:
        return False
    if n_index >= n or m_index >= m or k_index >= k:
        return False
    if plate[n_index][m_index][k_index] == "#":
        return False
    return True

def check_directions(n_index, m_index, k_index):
    global total
    global DIRS
    if check_legal(n_index, m_index, k_index):
        total = total + 1
        plate[n_index][m_index][k_index] = "#"

        for d in DIRS:
            check_directions(n_index + d[0], m_index + d[1], k_index + d[2])

input()

x, y = [int(x) for x in input().split()]
check_directions(x - 1, y - 1, 0)

print(total)
