n = int(input())
s = input()
table = {x: 2**i for i, x in enumerate(map(chr, range(97, 123)))}

SEG_LEN = n
SEG = [0]*(SEG_LEN*2)


def update(i, x):
    i += SEG_LEN
    SEG[i] = table[x]
    while i > 0:
        i //= 2
        SEG[i] = SEG[i*2] | SEG[i*2+1]


def find(left, right):
    left += SEG_LEN
    right += SEG_LEN
    ans = 0
    while left < right:
        if left % 2 == 1:
            ans = SEG[left] | ans
            left += 1
        left //= 2
        if right % 2 == 1:
            ans = SEG[right-1] | ans
            right -= 1
        right //= 2
    return format(ans, 'b').count('1')


for i, c in enumerate(s):
    update(i, c)

q = int(input())
for _ in range(q):
    com, *query = input().split()
    if com == '1':
        idx, x = query
        update(int(idx)-1, x)
    else:
        L, R = map(int, query)
        print(find(L-1, R))
