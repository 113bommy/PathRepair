from collections import deque


def solve(n):
    if n < 4:
        return -1
    q = deque()
    q.append(1)
    q.appendleft(3)
    q.append(4)
    q.append(2)
    turn = 1
    num = 5
    while num < n:
        if turn == 1:
            q.append(num)
        else:
            q.appendleft(num)
        num += 1
        turn = 1 - turn
    return ' '.join(str(x) for x in q)


if __name__ == '__main__':
    T = int(input())
    for case in range(T):
        print(solve(int(input())))
