#кто прочтет тот здохнет

def summ(l):
    #print(l)
    res = 0
    i = len(l)-1
    while i >= 0:
        res+=l[i]
        i-=2
    
    return res

n, h = map(int, input().split())
b = list(map(int, input().split()))

m = n
for i in range(1, n):
    if summ(sorted(b[0:i])) > h:
        m = i-1
        break
    
print(m)
