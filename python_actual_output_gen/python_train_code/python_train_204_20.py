def insert(left, right, scores, val):
    while left < right:
        mid = left + (right-left) // 2
        if val == scores[mid]:
            left = mid
            break
        elif (val[0] > scores[mid][0]) or (val[0] == scores[mid][0] and val[1] < scores[mid][1]):
            right = mid
        else:
            left = mid + 1
    
    scores.insert(right, val)
    return scores

n, k = map(int, input().split())
counter = {}

scores = []
for _ in range(n):
    key = tuple(map(int, input().split()))
    counter[key] = counter.get(key, 0) + 1
    insert(0, len(scores), scores, key)
    
print(counter[scores[k-1]])