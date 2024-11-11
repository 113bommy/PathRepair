import copy

def partition(p, r):
    i = p
    for j in range(p, r):
        if A[r][1] >= A[j][1]:
            A[i], A[j] = A[j], A[i]
            i += 1
    A[r], A[i] = A[i], A[r]
    return i

def quick_sort(p, r):
    if p < r:
        q = partition(p, r)
        quick_sort(p, q-1)
        quick_sort(q+1, r)

def is_stable():
    for i in range(N-1):
        if A[i][1] == A[i+1][1]:
            small_idx, large_idx = 0, 0
            for j in range(N-1):
                if A[i] == orig_list[j]:
                    small_idx = j
                elif A[i+1] == orig_list[j]:
                    large_idx = j
            if small_idx > large_idx:
                return False
    return True


N = int(input())
A = []
for _ in range(N):
    suit, num = input().split()
    num = int(num)
    A.append([suit, num])
orig_list = copy.deepcopy(A)

quick_sort(0, N-1)

is_stable = is_stable()
if is_stable:
    print("Stable")
else:
    print("Not Stable")

for card in A:
    print("%s %d" % (card[0], card[1]))
