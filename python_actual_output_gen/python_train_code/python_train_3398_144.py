n, r = map(int,input().split())
print(r)
if n < 10:
    r = r + 100*(10-n)
print(r)