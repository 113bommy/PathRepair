# Problem 1145 A - Thanos Sort

# input
N = int(input())
n_list = list(map(int, input().split()))

# initialization
max_size = 0

# search
def search_list(l, n):
    # is sorted
    tmp = sorted(l)
    if tmp==l:
        return n

    l_1 = l[:int(n/2)]
    l_2 = l[int(n/2):]
    return max(search_list(l_1, n/2), search_list(l_2, n/2))

max_size = search_list(n_list, N)

# output
print(max_size)
