q = int(input())
for _ in range(q):
    s = input()
    t = input()
    p = input()
    j = 0
    for i in range(len(t)):
        if j == len(s):
            break
        if t[i] == s[j]:
            j += 1
    if j != len(s):
        print("NO")
    else:
        dic = {}
        dic_t = {}
        for i in range(len(s)):
            if s[i] not in dic:
                dic[s[i]] = 1
            else:
                dic[s[i]] += 1
        for i in range(len(p)):
            if p[i] not in dic:
                dic[p[i]] = 1
            else:
                dic[p[i]] += 1
        for i in range(len(t)):
            if t[i] not in dic_t:
                dic_t[t[i]] = 1
            else:
                dic_t[t[i]] += 1
        data = list(dic.keys())
        data_t = list(dic_t.keys())
        for i in range(len(data_t)):
            if data_t[i] not in data:
                print("NO")
                #print(2)
                break
        else:
            for i in range(len(data)):
                if data[i] in dic_t:
                    if dic_t[data[i]] > dic[data[i]]:
                        print("NO")
                        #print(3)
                        break
            else:
                print("YES")

        
            