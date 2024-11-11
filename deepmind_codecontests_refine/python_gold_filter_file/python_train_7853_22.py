n = int(input())
beauty = input().split()
beauty = [int(x) for x in beauty]


beauty.sort()
max_beauty = beauty[-1] - beauty[0]

if max_beauty == 0:
	count = (n*(n-1)) // 2
else:
	base = beauty.count(beauty[0])
	end = beauty.count(beauty[-1])
	count = base * end

print(max_beauty, count)
