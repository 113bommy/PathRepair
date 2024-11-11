from sys import stdin
inFile = stdin
tokens = []
tokens_next = 0

def next_str():
    global tokens, tokens_next
    while tokens_next >= len(tokens):
        tokens = inFile.readline().split()
        tokens_next = 0
    tokens_next += 1
    return tokens[tokens_next - 1]

def nextInt():
    return int(next_str())

n = nextInt()
a = sorted([nextInt() for _ in range(n)])

min_dis = (10 ** 6, 0)
for i in range(len(a) - 1):
	cur = abs(a[i] - a[i + 1])
	if cur < min_dis[0]:
		min_dis = (cur, 0)
	if cur == min_dis[0]:
		min_dis = (min_dis[0], min_dis[1] + 1)

print("{} {}".format(min_dis[0], min_dis[1]))