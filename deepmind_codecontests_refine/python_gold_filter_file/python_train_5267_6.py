n, k = map(int, input().split())
words = []
for i in range(ord('A'), ord('Z') + 1):
    for j in range(ord('a'), ord('z') + 1):
        words.append(chr(i) + chr(j))

our = input().split()
 
res = [i for i in range(n)]
for j in range(50):
    for i in range(len(our)):
        if our[i] == 'NO':
            res[i] = res[i + k - 1]

for elem in res:
    print(words[elem],end=' ')