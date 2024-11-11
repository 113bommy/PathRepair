a, b = map(int, input().split())

def divisors(n):
    div = []

    for i in range(1, int(n ** (1 / 2)) + 1):
        if n % i == 0:
            div.append(i)
            if i * i != n:
                div.append(n // i)

    return sorted(div)

d = [*set(divisors(a)).intersection(divisors(b))]

for _ in range(int(input())):
	l, r = map(int, input().split())
	from bisect import bisect_left
	t = bisect_left(d, r)
	print(d[t] if t < len(d) and d[t] == r else d[t - 1] if d[t - 1] >= l else -1)