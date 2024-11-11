S = list(input())
len_S = len(S)
a = [0]*(len_S+1)
for i, s in enumerate(S):
    if s == '<':
        a[i+1] = a[i]+1
for i, s in enumerate(S[::-1]):
    inv_i = len_S-1-i
    if s == '>':
        a[inv_i] = max(a[inv_i+1]+1, a[inv_i])
print(sum(a))
