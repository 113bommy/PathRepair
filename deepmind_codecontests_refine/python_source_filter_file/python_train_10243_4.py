def play(s, t):
    count1, count2 = 0, 0
    for elem in s:
        if elem == '1':
            count1 += 1
    for elem in t:
        if elem == '1':
            count2 += 1
    if count2 - count1 > 1 or (count2 - count1 == 0 and count2 % 2 == 0):
        return "NO"
    return "YES"


a = input()
b = input()
print(play(a, b))
