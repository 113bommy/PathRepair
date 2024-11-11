def mutual(s1, s2):
    index = 0
    count = 0
    for i in s1:
        if len(s2) == index:
            return len(s1) - count + len(s2) - count
        if i == s2[index]:
            index += 1
            count += 1
    return len(s1) - count + len(s2) - count


pows = [1]
while pows[-1] < 1e12:
    pows.append(pows[-1] * 2)
pows = [str(i) for i in pows]

for i in range(int(input())):
    k = input()
    m = float('inf')
    move = None
    for i in pows:
        count = mutual(k, i)
        if m > count:
            move = i
            m = count
    print(m)
