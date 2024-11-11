n, b, d = map(int, input().split())

nums = list(map(int, input().split()))

sol =0 
cur = 0 
for n in nums : 
    if n <= b :
        cur += n
    if cur >= d:
        cur = 0
        sol+=1

print(sol)
