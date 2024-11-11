n, m = map(int, input().split())
dif = []; foo = 0; cnt = 0
for i in range(n):
    a, b = map(int, input().split())
    dif.append(a-b)
    foo += a
dif.sort(); dif.reverse()
if foo <= m: print(0)
else:
    for i in dif:
        foo -= i
        cnt += 1
        if foo <= m:
            print(cnt)
            exit()
print(-1)
    
