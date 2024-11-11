n = int(input())


def dfs(s):
    if int(s) > n:
        return 0
    ret = 1 if all(s.count > 0 for c in '753') else 0
    for c in '753':
        ret += dfs(s + c)
    return ret


print(dfs('0'))
