from collections import deque


def main():
    n, m = map(int, input().split())
    vertex = [-1]*(max(n, m) * 2)
    queue = deque()
    queue.append(n)
    vertex[n] = 0
    while queue:
        pos = queue.popleft()
        red = pos * 2
        blue = pos - 1
        if m > n and red <= 2*m and vertex[red] == -1:
            queue.append(red)
            vertex[red] = vertex[pos] + 1
        if blue >= 0 and vertex[blue] == -1:
            queue.append(blue)
            vertex[blue] = vertex[pos] + 1
        if vertex[m] != -1:
            break
    print(vertex[m])


if __name__ == "__main__":
    main()
