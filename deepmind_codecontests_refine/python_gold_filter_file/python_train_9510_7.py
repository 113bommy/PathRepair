n = int(input())

l = [int(i) for i in input().split()]


if n ==1:
    print('1')
else:    

    m= min(l)
    ind = l.index(m)
    l.remove(m)
    mm = min(l)
    if m == mm:
        print('Still Rozdil')
    else:
        print(ind+1)