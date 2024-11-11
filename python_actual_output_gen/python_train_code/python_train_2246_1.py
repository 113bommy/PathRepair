def count9 (x) :
    cnt = 0
    while x > 0 :
        if x % 10 == 9 :
            cnt += 1
        else :
            break
        x //= 10
    return cnt
p, d = map (int, input ().split ())
res = p; i = 10; f = 0
while 1 :
    if p % i >= d :
        break
    f = 1
    res = p - p % i
    i *= 10
if count9 (int (res - 1)) == count9 (int (p)) and int (p) > int (res) :
    res = p; f = 0
print (res - 1 if f else res)
