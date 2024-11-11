import math

def round_school(x):
    i, f = divmod(x, 1)
    return int(i + ((f >= 0.5) if (x > 0) else (f > 0.5)))

x = int(input())
current = -1

for _ in range(x):
	s, d = map(int, input().split())

	if current == -1:
		current = s
	else:
		remain = current - s
		if remain < 0:
			current = s
		else:
			remain = remain / d
			remain = math.ceil(remain)
			current = s + d * remain

print(current)