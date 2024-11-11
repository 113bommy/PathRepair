t=int(input())
pairs = [(1, 12), (2, 6), (3, 4), (4, 3), (6, 2), (12, 1)]
for _ in range(t):
    a = list(input())
    #print(a)
    #position = [i+1 for i in range(12) if a[i] == 'X' ]
    a = [(ord(i) - ord('O')) for i in a]
    ans = []
    for i in pairs:
        for j in range(i[1]):
            if all(a[j::i[1]]):
                #print(a[j::i[1]])
                ans.append(i)
                break
    an = ""
    an+=(str(len(ans)) + " ")
    for i in ans:
        an+=(str(i[0])+'*'+str(i[1])+' ')
    print(an)
