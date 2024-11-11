input()

fst = [int(x) for x in input().split()]
snd = [int(x) for x in input().split()]

def count(arr):
    res = {i: 0 for i in range(1, 6)}
    for i in arr:
        res[i]+=1
    return res

def solve():
    total = count(fst+snd)
    fst_ = count(fst)
    snd_ = count(snd)
    
    for v in total.values():
        if v%2!=0: return -1
    res = 0
    for k, v in fst_.items():
        diff = v - total[k]//2
        res += (diff if diff>0 else 0)
    return res
print(solve())