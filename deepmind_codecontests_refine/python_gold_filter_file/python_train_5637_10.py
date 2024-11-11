from collections import Counter

a = input()
b = [int(x) for x in input().split()]
c = []

for i in range(len(b)):
    c += [b[i] + x for x in b[i+1:]]
    
data = Counter(c)
print(data.most_common(1)[0][1])
