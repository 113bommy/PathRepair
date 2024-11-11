for T in range(int(input())):
    b, a, p = map(int, input().split(" "))
    s = " " + input()[::-1]
    #print(s)
    cost = 0
    i_min = 1
    pre = 'A' if s[2] == 'B' else 'B'
    while i_min < len(s):
        j = i_min + 1
        if pre == 'A':
            while j < len(s):
                if j == len(s)-1 or (s[j] == 'B' and s[j+1] == 'A'):
                    break
                j += 1
            if cost + a <= p:
                cost += a
                i_min = j
                pre = 'B'
            else:
                break
        else:
            while j < len(s):
                if j == len(s)-1 or (s[j] == 'A' and s[j+1] == 'B'):
                    break
                j += 1
            if cost + b <= p:
                cost += b
                i_min = j
                pre = 'A'
            else:
                break
        #print(i_min, cost)
    print(len(s) - i_min)





