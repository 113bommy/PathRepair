import itertools

def check(curr_words, line):
    if curr_words == []: 
        return True
    for i in range(len(line)):
        if line[i] == curr_words[0]:
            return check(curr_words[1:], line[i+1:])
    return False

n = int(input())
words = input().split()
m = int(input())
res, idx = 0, 0
for i in range(m):
    line = input().split()[1:]
    for p in itertools.permutations(range(n)):
        curr_words = [words[j] for j in p]
        cnt = 0
        for j in range(n):
            cnt += len([k for k in range(j+1, n) if p[k] < p[j]])
        v = n * (n-1) // 2 - cnt + 1
        if check(curr_words, line[:]) and v > res: 
            res, idx = v, i+1
if res > 0:
    print(idx)
    print('[:'+str('|'*res)+':]')
else:
    print('Brand new problem!')