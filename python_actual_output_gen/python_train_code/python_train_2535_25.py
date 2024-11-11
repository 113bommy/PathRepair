rows = [ input() for i in range(8) ]
cols = [0] * 8
for i in range(8):
    cols[i] = "".join([ row[i] for row in rows ])

white, black = 100, 100
for col in cols:
    firstB, firstW = col.find('B'), col.find('W')
    if firstW != -1 and ( firstB == -1 or firstB > firstW):
        white = min(white, firstW)

    lastB, lastW = col.rfind('B'), col.rfind('W')
    if lastB != -1 and (lastW == -1 or lastW < lastB):
        black = min(black, 8 - lastB)
if white <= black:
    print('A')
else:
    print('B')