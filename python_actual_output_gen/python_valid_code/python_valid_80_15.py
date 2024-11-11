n, m, r = map(int, input().split())
b = sorted(list(map(int, input().split())))[0]
s= sorted(list(map(int, input().split())))[-1]
p, q = divmod(r, b)
print(p*s*q if p*s*q>r else r)