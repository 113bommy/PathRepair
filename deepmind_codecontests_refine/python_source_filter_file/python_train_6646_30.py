from collections import deque, defaultdict

n,m = map(int, input().split())
a = [list(map(int, input().split())) for i in range(n)]
def check(x):
    """
    最大値をx以下にできるか？
    """
    used = [0]*n
    if x >= n:
        return True
    # NM
    b = [deque(a[i]) for i in range(n)]
    d = defaultdict(list)

    ng = set()
    while True:
        for i in range(n):
            if used[i]:
                continue
            while b[i] and b[i][0] in ng:
                b[i].popleft()
            if not b[i]:
                return False
            like = b[i].popleft()

            d[like].append(i)
            used[i] = 1
        # チェック
        flag = True
        for key, value in d.items():
            if len(value) > x:
                flag = False
                ng.add(key)
                for v in value:
                    used[v] = 0
                d[key].pop()
        if flag:
            return True

left = 0
right = n
while right - left > 1:
    mid = (left+right)//2
    if check(mid):
        right = mid
    else:
        left = mid
print(right)