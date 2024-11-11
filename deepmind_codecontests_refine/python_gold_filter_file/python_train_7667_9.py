n = int(input())
arr = map(str, input().strip().split())
d = {}

for ele in arr:
    s = set(ele)
    k = ""
    for item in s:
        k += item
    k = "".join(sorted(k))

    if k in d:
        d[k] += 1
    else:
        d[k] = 1

print(len(d))
