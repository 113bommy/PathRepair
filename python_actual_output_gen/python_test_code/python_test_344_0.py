import sys

n, k = map(int, input().split())
imos = dict()

for li, ri in (map(int, line.split()) for line in sys.stdin.buffer):
    imos[li*2] = imos[li*2]+1 if li*2 in imos else 1
    imos[ri*2+1] = imos[ri*2+1]-1 if ri*2+1 in imos else -1

acc = 0
ans = []
append = ans.append
minf = -(10**9 * 2 + 1)
left = minf


for x in sorted(imos.keys()):
    acc += imos[x]

    if left != minf and acc < k:
        append(str(left >> 1) + ' ' + str(x >> 1))
        left = minf
    elif left == minf and acc >= k:
        left = x


sys.stdout.buffer.write(
    (str(len(ans)) + '\n' + '\n'.join(ans)).encode('utf-8'))
