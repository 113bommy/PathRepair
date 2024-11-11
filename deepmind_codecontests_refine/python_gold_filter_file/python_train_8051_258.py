n = int(input())
vol = input().split()
vol = [int(x) for x in vol]

res = sum(vol)/n
print(res)