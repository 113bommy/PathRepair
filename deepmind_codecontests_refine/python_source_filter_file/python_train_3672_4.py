import collections

def DCJ(n, heights):
    # We have n buildings: num(heights) == n
    # Let's denote the building with its index i.e. 0 to (n-1)th buildings

    # path[i]: buildings reachable within one jump from ith building
    # Initializing: jump from ith to (i+1)th building is always possible
    path = [{i+1} for i in range(n)]
    
    # There are 4 cases to consider (look at editorial)
    # Let's say we stand on ith building
    # 1-1: first jth building s.t. j > i, heights[j] >= heights[i]
    # 1-2: first jth building s.t. j > i, heights[j] <= heights[i]
    # 2-1: first jth building s.t. j < i, heights[j] > heights[i]
    # 2-2: first jth building s.t. j < i, heights[j] < heights[i]

    # filling {path} using monotonic sequence characteristic
    def monotonic(x):
        temp = []   # we will use this as a temporary stack

        # 1-1, 1-2
        for i, h in enumerate(x):
            while temp and temp[-1][1] < h:
                temp.pop()
            if temp:
                path[temp[-1][0]].add(i)
            temp.append((i, h))

        temp = []

        # 2-1, 2-2
        for i, h in enumerate(x[::-1]):
            while temp and temp[-1][1] <= h:
                temp.pop()
            if temp:
                path[n-1-i].add(temp[-1][0])
            temp.append((n-1-i, h))

    monotonic(heights)                   # 1-1, 2-1
    monotonic([-x for x in heights])     # 1-2, 2-2
    
    # BFS: shortest path 
    visited = [1] + [0] * (n-1)
    queue = collections.deque()
    queue.append((0, 1))

    while queue:
        i, jump = queue.popleft() 

        for j in path[i]:
            if j == n-1:    return jump

            if not visited[j]:
                visited[j] = 1
                queue.append((j, jump+1))


if __name__ == "__main__":
    n = int(input())                                # number of buildings
    heights = list(map(int, input().split(' ')))    # heights of buildings
    print(DCJ(n, heights))                          # Discrete Centrifugal Jumps
