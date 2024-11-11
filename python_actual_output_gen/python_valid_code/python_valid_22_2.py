input()
data = [int(i) for i in input().split()]
ex = {}
ex["chest"] = sum(data[::3])
ex["biceps"] = sum(data[1::3])
ex["back"] = sum(data[2:3])
print(max(ex, key = ex.get))
