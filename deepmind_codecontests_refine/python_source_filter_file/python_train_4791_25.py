class Node:
    def __init__(self, key):
        self.key = key
        self.left = left
        self.right = right

H = int(input())
heap = [0] * (H+1)
for i, num in enumerate(map(int, input().split())):
    heap[i+1] = num

print(*heap)

def get_parent(heap, i):
    if i // 2 > 0:
        return heap[i // 2]
    else:
        return None

def get_left_child(heap, i):
    if 2 * i <= H:
        return heap[2 * i]
    else:
        None

def get_right_child(heap, i):
    if 2 * i + 1 <= H:
        return heap[2 * i + 1]
    else:
        return None
for i in range(1, H+1):
    msg = 'node ' + str(i) + ': key = ' + str(heap[i]) + ', '
    parent_key = get_parent(heap, i)
    # print(parent_key)
    if parent_key:
        msg += 'parent key = ' + str(parent_key) + ', '

    left_key = get_left_child(heap, i)
    if left_key:
        msg += 'left key = ' + str(left_key) + ', '

    right_key = get_right_child(heap, i)
    if right_key:
        msg += 'right key = ' + str(right_key) + ', '
    print(msg)
