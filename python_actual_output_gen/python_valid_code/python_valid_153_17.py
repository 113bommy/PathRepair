N = int(input())
S = input()

length = 0 

for i in range(N):
    l1 = i
    l2 = i + length
    _word = S[l1:l2]
    _S = S[l2:]
    while _word in _S and l1 + len(_word) < l2:
        l2 += 1
        _word = S[l1:l2]
        _S = S[l2:]
    length = max(len(_word)-1, length)

print(length)
