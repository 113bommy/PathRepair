arr = [int(i) for i in input().split()]
result = []
for i in range(14):
    copy = list(arr)
    store = copy[i]
    copy[i] = 0
    for j in range(i+1, i + 14):
        j = j % 14
        copy[j] += store // 14
    store -= (store // 14) * 14
    for j in range(i+1, i + 14):
        j = j % 14
        if store: copy[j] += 1
        else: break
        store -= 1
    result.append(sum([i for i in copy if i % 2 == 0]))
print(max(result))