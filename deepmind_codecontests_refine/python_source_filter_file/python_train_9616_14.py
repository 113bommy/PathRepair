def f(x):
    if x % 2 == 0:
        return 1
    else:
        return -1


n = int(input())
t = 0
li_ = list(map(int,input().split()))
if f(li_[0]*li_[1]) == 1:
    while t < n:
        if f(li_[t]) != f(li_[0]):
            break
        else:
            t += 1
else:
    if li_[0]*li_[2] == 1:
        t = 1
    else:
        t = 0
t += 1
print(t)