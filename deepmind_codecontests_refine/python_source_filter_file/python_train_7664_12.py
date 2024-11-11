import bisect

def list_output(s):    
    print(' '.join(map(str, s)))
    
def list_input(s='int'):
    if s == 'int':
        return list(map(int, input().split()))    
    elif s == 'float':
        return list(map(float, input().split()))
    return list(map(str, input().split()))

n = int(input())
d = dict()
for _ in range(n):
    seq = list(input().split())
    name = seq[0]
    k = int(seq[1])
    seq = seq[2:]
    if name not in d:
        d[name] = []
    d[name].extend(seq)

for key in d:
    seq = d[key]
    seq = list(set(seq))
    k = len(seq)
    valid = [True] * k
    for i in range(k):
        if not valid[i]:
            continue        
        for j in range(k):
            if i == j or not valid[j]:
                continue
            if seq[i].endswith(seq[j]):
                valid[j] = False
            if seq[j].endswith(seq[i]):
                valid[i] = False
    vseq = list()
    for i in range(k):
        if valid[i]:
            vseq.append(seq[i])
    d[key] = vseq

sz = len(d)
for key in d:
    seq = d[key]    
    k = len(seq)
    seq = ' '.join(seq)
    print('{} {} {}'.format(key, k, seq))


    
