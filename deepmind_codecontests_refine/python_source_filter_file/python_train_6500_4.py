def helper():
    n = int(input())
    l = list(map(int, input().split()))
    pref_1 = []
    temp = 0
    for i in l:
        temp += i
        pref_1.append(temp)

    l.sort()
    pref_2 = []
    temp = 0
    for i in l:
        temp += i
        pref_2.append(temp)

    m = int(input())
    for i in range(m):
        type, l, r = map(int, input().split())

        if type == 1:
            answer = pref_1[r-1]
            if l > 1:
                answer -= pref_1[l-1]

        else:

            answer = pref_2[r-1]
            if l > 1:
                answer -= pref_2[l-1]

        print(answer)



helper()
