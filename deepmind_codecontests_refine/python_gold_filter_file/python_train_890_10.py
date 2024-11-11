def int_lst_input():
    return [int(val) for val in input().split(' ')]

def int_input():
    return int(input())

def print_lst(lst):
    print(' '.join([str(val) for val in lst]))

def solve():
    n, m, z = int_lst_input()
    n_min, m_min = set(), set()
    # n_min = {n * i for i in range(1, z + 1) if n * i <= z}
    # m_min = {m * i for i in range(1, z + 1) if m * i <= z}

    i = 1
    while n * i <= z:
        n_min.add(n * i)
        i += 1

    i = 1
    while m * i <= z:
        m_min.add(m * i)
        i += 1

    print(len(n_min.intersection(m_min)))

if __name__ == '__main__':
    solve()
