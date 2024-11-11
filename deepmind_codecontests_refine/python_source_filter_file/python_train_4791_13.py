def print_heap():
    for i in range(n):
        if (i-1)//2 in range(n):
            if 2*i+1 in range(n):
                if 2*1+2 in range(n):
                    print("node {}: key = {}, parent key = {}, left key = {}, right key = {},"
                          .format(i+1, heap[i], heap[(i-1)//2], heap[2*i+1], heap[2*i+2]))
                else:
                    print("node {}: key = {}, parent key = {}, left key = {},"
                          .format(i+1, heap[i], heap[(i-1)//2], heap[2*i+1]))
            else:
                print("node {}: key = {}, parent key = {},"
                      .format(i+1, heap[i], heap[(i-1)//2]))
        else:
            if 2*i+1 in range(n):
                if 2*1+2 in range(n):
                    print("node {}: key = {}, left key = {}, right key = {},"
                          .format(i+1, heap[i], heap[2*i+1], heap[2*i+2]))
                else:
                    print("node {}: key = {}, left key = {},"
                          .format(i+1, heap[i], heap[2*i+1]))
            else:
                print("node {}: key = {},".format(i+1, heap[i]))


if __name__ == "__main__":
    n = int(input())
    heap = list(map(int, input().split()))
    print_heap()