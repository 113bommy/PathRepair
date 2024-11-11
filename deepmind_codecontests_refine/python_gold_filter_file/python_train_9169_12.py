from collections import Counter

n = int(input())
a = list(map(int, input().split(' ')))

def mode(lst):
    data = Counter(lst)
    return data[data.most_common(1)[0][0]]

print(mode(a))
