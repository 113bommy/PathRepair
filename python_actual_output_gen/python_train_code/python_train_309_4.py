n,m,z = map(int,input().split())
q = 0
ne = n
me = m
for i in range(0,z):
    if (ne-1<=z) and (me-1<=z):
        if me<ne:
            while me<ne:
                me += m
        elif ne<me:
            while ne<me:
                ne += n
        else:
            if ne==me:
                q += 1
                ne += n
                me += m
    else:
        break
print(q)