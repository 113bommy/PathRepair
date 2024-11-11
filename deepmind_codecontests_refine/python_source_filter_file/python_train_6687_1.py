def go():
    d, m = map(int, input().split())
    i = d.bit_length()
    res = 0
    while i >= 0:
        bi = 1 << i
        if d >= bi:
            res += bitvals[i] * (d - bi + 1)
            res = res%m
            d=bi-1
        i -= 1
    return res%m


bitvals = [1]
for i in range(12):
    bitvals.append(bitvals[-1] * (2 ** i + 1))
print(bitvals)

# x,s = map(int,input().split())
t = int(input())
# t = 1
ans = []
for _ in range(t):
    # print(go())
    ans.append(str(go()))
#
print('\n'.join(ans))
