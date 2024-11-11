import collections

n = int(input())
s = input()

s1 = s[:n]
s2 = s[-1:-(n + 1):-1]

s_1 = collections.defaultdict(int)
s_2 = collections.defaultdict(int)h
for i in range(2 ** n):
    bin_i = bin(i + 2 ** n)
    sequence1 = ""
    sequence1_inverse = ""
    sequence2 = ""
    sequence2_inverse = ""
    for j in range(n):
        if bin_i[j + 3] == "1":
            sequence1 += s1[j]
            sequence2 += s2[j]
        else:
            sequence1_inverse += s1[j]
            sequence2_inverse += s2[j]
    s_1[sequence1 + "-" + sequence1_inverse] += 1     
    s_2[sequence2 + "-" + sequence2_inverse] += 1
ans = 0
for i in dict(s_1):
    ans += s_1.get(i, 0) * s_2.get(i, 0)
    '''
    if i in dict(s_2):
        ans += dict(s_1)[i] * dict(s_2)[i]
    '''
print(ans)
