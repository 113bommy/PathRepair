s = input()
t = input()

ct = 0
k = 0
for i in t:
    f = s.find(i, k)
    if f < 0:
        ct += 1
        f = s.find(i)
        if f == -1:
            print(-1)
            break
        else:
            k = f+1
    else:
        k = f+1
else:
    print(ct*len(s)+k)
