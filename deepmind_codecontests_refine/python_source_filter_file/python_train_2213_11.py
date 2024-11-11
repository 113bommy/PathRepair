from sys import stdin

n, m = map(int, stdin.readline().rstrip().split(" "))
x, k, y = map(int, stdin.readline().rstrip().split(" "))
l = list(map(int, stdin.readline().rstrip().split(" ")))
l2 = list(map(int, stdin.readline().rstrip().split(" ")))
z = {}
for i in range(n):
    z[l[i]]=i
mana = 0
start = -1
arr = []
for i in range(m):
    a = z[l2[i]] - start
    if start == -1:
        max_border = l2[i]
    else:
        max_border = max([l2[i], start])
    if a < 0:
        mana = -1
        break
    elif a > 1:
        c = 0
        ma = 0

        for j in range(start+1 ,z[l2[i]]):
            c+=1
            ma = max(ma, l[j])
        if c < k and ma > max_border:
            mana = -1
            break
        else:
            if k*y < x:
                if ma > max_border:
                    adding = x + (c - k)*y
                    mana += adding
                else:
                    adding = c*y
                    mana += adding
            else:
                adding =  (c // k) * x + y * (c% k)
                mana += adding
    start = z[l2[i]]
if mana!= -1:
    if l2[-1]!=l[-1]:
        c = 0
        ma = 0
        for i in range(z[l2[-1]]+1, n):
            ma = max(ma, l[i])
            c+=1
        if c < k and ma > l2[-1]:
            mana = -1
        else:
            if k * y < x:
                if ma > l2[-1]:
                    adding = x + (c - k) * y
                    mana += adding
                else:
                    adding = c * y
                    mana += adding
            else:
                adding = (c // k) * x + y * (c% k)
                mana += adding

print(mana)

