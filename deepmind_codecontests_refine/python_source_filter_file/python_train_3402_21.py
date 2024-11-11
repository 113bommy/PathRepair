def is_power2(num):
	return ((num & (num - 1)) == 0)


def maybeAdd(dot, peers):
    for peer in peers:
        if not is_power2(abs(dot - peer)):
            return False
    peers.append(dot)

n = int(input())
dots = list(map(int, input().split()))
m = min(dots)
M = max(dots)

l = {}
for dot in dots:
    l[dot] = True

ans = []
att = []

for dot in dots:
    att = [dot]
    maxpow = max(abs(dot - m), abs(dot - M)).bit_length() - 1

    diff = 1
    for pow in range(maxpow):
        if dot - diff in l:
            maybeAdd(dot - diff, att)
        if dot + diff in l:
            maybeAdd(dot + diff, att)
        diff *= 2

    if len(att) > len(ans):
        ans = att

print(len(ans))
print(*ans)
