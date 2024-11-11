from collections import deque
n = int(input())
ar = deque()
i = 0
for i in range(n):
    s = input()
    j = 0
    ct = 0
    while s[j].isalpha():
        j += 1  #iterates over letters and counts them if from system 1 ex.AB12
        ct += 1
    while j < len(s) and s[j].isnumeric():
        j += 1    #iterates over digits until hit a character or end
    if j == len(s):    #if it ended then its system 1 AB12
        j = 0
        col = 0
        ct -= 1
        while s[j].isalpha():
            col += (ord(s[j])-ord('A')+1)*pow(26,ct)
            ct -= 1
            j += 1
        print('R'+s[j:]+'C'+str(col))
    else:
        j = 1
        while s[j].isdigit():
            j += 1
        r = s[1:j]
        c = int(s[j+1:])
        while c > 0:
            ar.appendleft(c % 26)
            c //= 26
        j = len(ar)-1
        while j > 0:
            if ar[j] <= 0:
                ar[j-1] -= 1
                ar[j] += 26
            j -= 1
        if ar[0] == 0:
            ar.popleft()
        b = []
        j = 0
        for j in range(len(ar)):
            b.append(chr(ar[j] + 64))
        for j in b:
            print(j, end='')
        print(r)
        ar.clear()
