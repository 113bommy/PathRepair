n = int(input())
_ = input()
ar = list(map(int, input().split()))

idx = 0
idx2 = 0
flag = False

for i, e in enumerate(ar):
    idx = max(idx, 0 if e == 0 else i-e+2)
    
    if e == 1 and idx2 < i:
        flag = True
        i1 = i
        s = 0

    idx2 = max(idx2, 0 if e == 0 else i+n-e)

    if flag:
        if s+1 == e:
            s += 1
        else:
            flag = False

if flag:
    print(i1)
else:
    print(n + idx)