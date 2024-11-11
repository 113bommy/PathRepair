# @author: guoyc
# @date: 2018/7/23

N, diff = [int(_) for _ in input().split()]

books = [int(_) for _ in input().split()]

dec = []
inc = []

ml = 0
res = []

j = 0

for i, h in enumerate(books):
    while dec and books[dec[-1]] <= h:
        dec.pop()
    dec.append(i)
    while inc and books[inc[-1]] >= h:
        inc.pop()
    inc.append(i)

    while books[dec[0]] - books[inc[0]] > diff:
        if dec[0] < inc[0]:
            j = dec.pop(0) + 1
        else:
            j = inc.pop(0) + 1

    if i - j + 1 > ml:
        ml = i - j + 1
        res = []
    if i - j + 1 == ml:
        res.append((j, i))

print(ml, len(res))
for i, j in res:
    print(i, j)
