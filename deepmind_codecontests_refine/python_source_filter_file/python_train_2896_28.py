N, K = map(int, input().split())
a = [int(i) for i in input().split()]

s = [0]
for i in range(N) :
    s.append(s[-1] + a[i])

sub = []
for i in range(N + 1) :
    for j in range(i + 1, N + 1) :
        sub.append(s[j] - s[i])

ret = 0
for i in range(31, -1, -1) :
    sub_ = []
    for sv in sub :
        if sv & (1 << i) :
            sub_.append(sv)
            
    if len(sub_) >= K :
        ret += (1 << i)
        sub = sub_
    
print(ret)