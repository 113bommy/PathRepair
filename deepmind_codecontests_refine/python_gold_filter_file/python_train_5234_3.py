def solution(line, n):
    crnt_sum = 0
    res = []
    for idx, item in enumerate(line):
        crnt_sum += item
        if crnt_sum < n:
            res.append(item)
        else:
            if crnt_sum == n and (idx == len(line) - 1 or sum(line[idx+1:]) == 0):
                res.append(item)
            else:
                res.extend([0]*(len(line) - idx))
                while True:
                    if idx == 0:
                        res[0] = 0
                        res = [1] + res
                        break
                    else:
                        if res[idx-1] != 9:
                            res[idx-1] += 1
                            break
                        else:
                            res[idx-1] = 0
                            idx -= 1
                return(''.join(tuple(map(str, res))))
    return(''.join(tuple(map(str, res))))


n = int(input())
for _ in range(n):
    line, n = input().split()
    z = int(line)
    line = tuple(map(int, list(line)))
    n = int(n)
    print(int(solution(line, n)) - z)
