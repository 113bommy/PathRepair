w = input())
for s in set(w):
    if w.count(s) % 2 != 0:
        print('No')
        break
else:
    print('Yes')