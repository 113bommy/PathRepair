from collections import deque

def push(duque, d, x):
    if d == 0:
        duque.append(x)
    else:
        duque.appendleft(x)
    return duque

def randomAccess(duque, p):
    print(duque[p])

def pop(duque, d):
    if d == 0:
        duque.pop()
    else:
        duque.popleft()
    return duque

if __name__ == '__main__':
    l = deque([])
    n = int(input())
    for i in range(n):
        j= input().split()

        if int(j[0]) == 0:
            push(l, int(j[1]), int(j[2]))
        elif int(j[0]) == 1:
            randomAccess(l, int(j[1]))
        else:
            pop(l, int(j[1]))
