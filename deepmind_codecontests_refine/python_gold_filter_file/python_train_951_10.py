n = int(input())
a = list(map(int, input().split(' ')))

pl = 0
pr = len(a) - 1
last = 0
op = []

while pl <= pr:
    l = a[pl]
    r = a[pr]
    
    if l <= last and r <= last:
        break
    elif l <= last:
        op.append('R')
        last = r
        pr -= 1
    elif r <= last:
        op.append('L')
        last = l
        pl += 1
    else:
        if l < r:
            op.append('L')
            last = l
            pl += 1
        elif l > r:
            op.append('R')
            last = r
            pr -= 1
        else:
            # l == r
            llen = 1
            rlen = 1
            for i in range(pl + 1, pr + 1):
                if a[i] <= a[i - 1]:
                    break
                llen += 1
            for i in range(pr - 1, pl - 1, -1):
                if a[i] <= a[i + 1]:
                    break
                rlen += 1
            
            if llen >= rlen:
                while llen > 0:
                    op.append('L')
                    llen -= 1
            else:
                while rlen > 0:
                    op.append('R')
                    rlen -= 1

            break

print(len(op))
print(''.join(op))
