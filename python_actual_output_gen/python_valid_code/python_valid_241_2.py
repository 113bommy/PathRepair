N, K = [int(i) for i in input().split()]
s = [i for i in input().split()]
t = 0
for elem in s:
    count = 0
    for j in range(len(elem)):
        if elem[j] == '4' or elem[j] == '7':
            count += 1
        if count <= K:
            t += 1
print(t)
