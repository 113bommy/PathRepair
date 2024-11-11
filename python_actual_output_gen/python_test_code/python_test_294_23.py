for o in range(int(input())):
    s = input()
    dic = {1:[]}
    if len(s) == 1 and (s[0] == 0 or s[0] == 1):
        print(0)
    else:
        for i in range(len(s)):
            if s[i] == "1":
                dic[1].append(i)
        c = 0
        for i in range(len(dic[1])-1):
            if  dic[1][i+1] - dic[1][i]>1:
                c = c + dic[1][i+1] - dic[1][i]
        print(c)