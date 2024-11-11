a = 'xXAHIMoOTuUVvWwYy'
d = {'bd', 'pq'}
s = input()
n = len(s)
res = True
for i in range(n):
    x, y = s[i], s[n - i - 1]
    if x == y and x in a: continue
    if x + y in d or y + x in d:
        continue
    print("NIE") 
    exit()
print("TAK")
