# def makelist(n, m):
# 	return [[0 for i in range(m)] for j in range(n)]

# a = int(input())
# b, c = map(int, input().split())
# s = input()


par = [0]*202020
size = [0]*202020

def find(x):
	if par[x] == x:
		return x
	else:
		par[x] = find(par[x])
		return par[x]

def unite(x, y):
	x = find(x)
	y = find(y)
	res = size[x] * size[y]
	size[x] += size[y]
	par[y] = x
	return res

# main
n = int(input())
for i in range(202020):
	par[i] = i
	size[i] = 1

a = [0] + list(map(int, input().split()))
b = [0]*(n+1)
for i in range(1, n+1):
	b[a[i]] = i

ans = 0
for j in reversed(range(1, n+1)):
	i = b[j]
	ans += a[i]
	if i - 1 >= 1 and a[i-1] > a[i]:
		ans += unite(i-1, i) * a[i]
	if i + 1 <= n and a[i+1] > a[i]:
		ans += unite(i+1, i) * a[i]
print(ans)
