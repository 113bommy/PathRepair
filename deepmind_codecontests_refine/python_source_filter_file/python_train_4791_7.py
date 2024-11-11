n = int(input())
heap = list(map(int, input().split()))
for i in range(len(heap)):
    out = 'node {}: key = {}, '.format(i + 1, heap[i])
    parent = (i - 1) // 2
    out += 'parent key = {}, '.format(heap[parent]) if parent >= 0 else ''
    left = (2 * i) + 1
    out += 'left key = {}'.format(heap[left]) if left < len(heap) else ''
    right = (2 * i) + 2
    out += 'right key = {}'.format(heap[right]) if right < len(heap) else ''
    print(out)