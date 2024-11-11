import copy

def num_from_card(card):
    return int(card[2:])

def partition(A, p, r):
    x = num_from_card(A[r])
    i = p-1
    for j in range(p, r):
        if num_from_card(A[j]) <= x:
            i += 1
            A[i], A[j] = A[j], A[i]
    A[i+1], A[r] = A[r], A[i+1]
    return i+1

def quick_sort(A, p, r):
    if p < r:
        q = partition(A, p, r)
        quick_sort(A, p, q-1)
        quick_sort(A, q+1, r)

def merge(A, left, mid, right):
    L = A[left: mid]
    R = A[mid: right]
    L.append('  ' + str(int(10e9 + 1)))
    R.append('  ' + str(int(10e9 + 1)))
    i, j = 0, 0
    for k in range(left, right):
        if num_from_card(L[i]) <= num_from_card(R[j]):
            A[k] = L[i]
            i += 1
        else:
            A[k] = R[j]
            j += 1

def merge_sort(A, left, right):
    if left + 1 < right:
        mid = int((left + right)/2)
        merge_sort(A, left, mid)
        merge_sort(A, mid, right)
        merge(A, left, mid, right)

n = int(input())
cards = [input() for i in range(n)]
merge_cards = copy.copy(cards)

quick_sort(cards, 0, n-1)
merge_sort(merge_cards, 0, n-1)

if merge_cards == cards:
    print('Stable')
else:
    print('Not stable')

for c in cards:
    print(c)

