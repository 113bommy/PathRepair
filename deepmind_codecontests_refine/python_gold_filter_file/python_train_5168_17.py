n = int(input())
seq = list(map(int, input().split(' ')))
minimum = min(seq)
prev=-1
min_distance=n
for (i,c) in enumerate(seq):
    if c == minimum:
        if prev != -1 and i-prev < min_distance:
            min_distance = i-prev
        prev = i
print(min_distance)