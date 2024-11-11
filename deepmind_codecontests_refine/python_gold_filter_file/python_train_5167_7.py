s = input()
Len = len(s)
min_k = Len
for ch in set(s):
    last_idx, freq = -1, 0
    for i in range(Len):
        if s[i] == ch:
            freq = max(freq, i-last_idx)
            last_idx = i
    freq = max(freq, Len-last_idx)
    min_k = min(min_k, freq)
print(min_k)
