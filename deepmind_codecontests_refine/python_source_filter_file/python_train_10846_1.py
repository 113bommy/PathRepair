from collections import Counter

def countbit(x):
    ans = 0
    while x & 1:
        ans += 1
        x >>= 1
    return ans
    

n = int(input())
b = list(map(int,input().split()))

cnt = Counter()
for x in b:
    cnt[countbit(x)] += 1

mostcnt = cnt.most_common(1)
#mostcnt is list 

ans = []
for x in b:
    if countbit(x) != mostcnt[0][0]:
        ans.append(x)

print(len(ans))        
print(' '.join([str(x) for x in ans]))
