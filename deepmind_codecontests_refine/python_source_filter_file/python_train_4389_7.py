dic = {}
dic2 = {}
for i in range(97, 123):
    dic[chr(i)] = i
    dic2[i] = chr(i)

k = int(input())
word1 = input()
word2 = input()
ords = []
carry = 0
for i in range(k):
    c = dic[word1[i]] + dic[word2[i]] + carry
    carry = 0
    if c % 2 == 1:
        carry = 26
    ords.append(c//2) 


for i in range(k-1, -1, -1):
    if ords[i] > 122:
        ords[i-1] += 1
        ords[i] = dic2[ords[i] - 26]
    else:
        ords[i] = dic2[ords[i]]
ords.reverse()
print(''.join(ords))
