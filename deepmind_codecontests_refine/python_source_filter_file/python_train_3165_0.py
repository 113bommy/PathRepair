def main():
    intervals = []
    visited = []
    for _ in range(int(input())):
        read_input(intervals, visited)


def read_input(intervals: list, visited: list) -> None:
    command, x, y = [int(x) for x in input().split(" ")]

    if (command == 1):
        intervals.append((x, y))
        visited.append(False)
    else:
        # reset the visited array
        for x in range(len(visited)):
            visited[x] = False

        if(find_path(intervals, visited, x-1, y-1)):
            print("YES")
        else:
            print("NO")


def find_path(intervals: list, visited: list, start: int, end: int) -> bool:

    if (start == end):
        return True
    else:
        for x in range(len(intervals)):
            if (can_move(intervals[start], intervals[x]) and not visited[x]):
                visited[x] = True
                if(find_path(intervals, visited, x, end)):
                    return True

    return False


def can_move(a: tuple, b: tuple) -> bool:
    if (b[0] < a[0] < b[1]):
        return True
    elif (b[0] < a[1] < b[1]):
        return True
    else:
        return False


if __name__ == "__main__":
    main()
