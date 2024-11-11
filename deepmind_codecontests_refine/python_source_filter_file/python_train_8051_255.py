n = int(input())
vol = input().split()
vol = [int(x) for x in vol]

res = sum(vol)/100*n
print(res)