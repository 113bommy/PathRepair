[n, m, r] = list(map(int, input().split(" ")))
s = list(map(int, input().split(" ")))
b = list(map(int, input().split(" ")))

r = r % min(s) + (r // min(s))*max(b)
print(r)
