def solution():
    n = int(input())
    # number of participants
    cnt = {}
    # find the missing record
    for i in range(n * (n - 1) // 2 - 1):
        player = [int(i) for i in input().split()]
        if player[0] in cnt:
            cnt[player[0]][0].append(player[1])
        else:
            cnt[player[0]] = [[player[1]], []]
        if player[1] in cnt:
            cnt[player[1]][1].append(player[0])
        else:
            cnt[player[1]] = [[], [player[0]]]
    res = []
    for i in cnt:
        if len(cnt[i][0]) + len(cnt[i][1]) < n - 1:
            res.append(i)
    # find the match result using the given match results
    queue = [res[0]]
    head = 0
    visited = {res[0]}
    while head < len(queue):
        print(queue)
        if queue[head] == res[1]:
            print(res[0], res[1])
            break
        for i in cnt[queue[head]][0]:
            if i not in visited:
                visited.add(i)
                queue.append(i)
        head += 1
    else:
        print(res[1], res[0])



if __name__ == '__main__':
    solution()