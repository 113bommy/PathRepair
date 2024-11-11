n = int(input())
sherlock_card = [int(i) for i in input()]
moriati_card = [int(i) for i in input()]
sherlock_card.sort()
moriati_card.sort()
i = 0
moriati_hit = 0
for j in range(n):
    if moriati_card[j] > sherlock_card[i]:
        moriati_hit += 1
        i += 1
    else:
        continue
moriati_hited = 0
sherlock_card.sort(reverse=True)
moriati_card.sort(reverse=True)
i = 0
for j in range(n):
    if sherlock_card[j] > moriati_card[i]:
        moriati_hited += 1
    else:
        i += 0
print(moriati_hited)
print(moriati_hit)