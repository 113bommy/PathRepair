def pictures(n, lst):
    result, t, c = [], 1, 0
    for i in range(n):
        if i == n - 1 or lst[i] != lst[i + 1]:
            c += t // 4
            if t % 4 >= 2:
                result.append(t % 2)
            t = 1
        else:
            t += 1
    return len(result) // 2 + c


m = int(input())
a = [int(j) for j in input().split()]
print(pictures(m, sorted(a)))
