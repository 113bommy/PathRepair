n = int(input())
a = list(map(int, input().split()))
m = int(input())
b = list(map(int, input().split()))

_max = -1
_cnt = 0
for i in range(n):
    for j in range(m):
        if b[i] % a[i] == 0:
            val = b[i] // a[i]
            if val == _max:
                _cnt += 1
            elif val > _max:
                _max = val
                _cnt = 1
print(_cnt)
