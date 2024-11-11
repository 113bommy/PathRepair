import itertools

dx = (0, 0, 0, 1,-1, 1, 1,-1,-1,-2, 2, 0, 0)
dy = (0, 1,-1, 0, 0, 1,-1, 1,-1, 0, 0,-2, 2)
dd = (5, 9, 13)

def drop(fab, start, used, size_list):
    for xy in range(start, 100):
        y = xy%10
        x = xy//10
        size = size_list[used]
        for i in range(size):
            if not fab[y + dy[i] + 2][x + dx[i] + 2]:
                break
        else:
            for i in range(size):
                fab[y + dy[i] + 2][x + dx[i] + 2] -= 1
            if sum(map(sum, fab)):
                if size == size_list[used + 1]:
                    result = drop(fab, xy + 1, used + 1, size_list)
                else:
                    result = drop(fab, 0, used + 1, size_list)
                if result:
                    result.append([x, y, dd.index(size) + 1])
                    return result
                for i in range(size):
                    fab[y + dy[i] + 2][x + dx[i] + 2] += 1
            else:
                return [[x, y, dd.index(size) + 1]]
    return False

fab = [[0 for i in range(14)] for j in range(14)]

n = int(input())

for i in range(10):
    fab[i + 2][2:12] = list(map(int, input().split()))

s = sum(map(sum, fab))
d_all = list(itertools.combinations_with_replacement([5,9,13], n))
d_list = [l for l in d_all if sum(l) == s]

ans = [0 for i in range(n)]
for d in d_list:
    d_tmp = sorted(d)[::-1]
    ans = drop(fab, 0, 0, d_tmp)
    if ans:
        for a in ans:
            print(*a)
        break

