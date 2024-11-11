def same(x):
    return all(x[i] == x[0] for i in range(len(x)))
def dec(x):
    return all(x[i] < x[i-1] for i in range(1, len(x)))
def idx(x):
    return 0 if same(x) else 1 if dec(x) else 2

n = int(input())
name = [0] * n
cnt = [[0 for i in range(n)] for j in range(3)]
res = [ "If you want to call a taxi, you should call: ",
        "If you want to order a pizza, you should call: ",
        "If you want to go to a cafe with a wonderful girl, you should call: "]
for i in range(n):
    m, name[i] = input().split()
    m = int(m)
    for j in range(m):
        num = input().split('-')
        cnt[idx(num)][i] += 1
for i in range(3):
    mx = max(cnt[i])
    print(res[i], end='')
    x = []
    for j in range(n):
        if cnt[i][j] == mx:
            x.append(name[j])
    print(', '.join(x)+'.')
