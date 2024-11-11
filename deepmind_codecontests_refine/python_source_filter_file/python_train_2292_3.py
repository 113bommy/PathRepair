def maxHeapify(i, node_list):
    n = len(node_list)
    if 2*i+1 < n and node_list[2*i+1] > node_list[i]:
        i_largest = 2*i+1
        # node_list[i], node_list[2*i+1] = node_list[2*i+1], node_list[i]
    else:
        i_largest = i
    if 2*i+2 < n and node_list[2*i+2] > node_list[i_largest]:
        i_largest = 2*i+2
        # node_list[i], node_list[2*i+2] = node_list[2*i+2], node_list[i]

    if i_largest != i:
        node_list[i], node_list[i_largest] = node_list[i_largest], node_list[i]
        maxHeapify(i_largest, node_list)

n = int(input())
node_list = [int(i) for i in input().split()]
for i in range(n//2, -1, -1):
    maxHeapify(i, node_list)
print(' '.join([str(node) for node in node_list]))

