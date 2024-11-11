a = input()
n = int(input())
d = []
for i in range(n):
    s = list(map(str, input().split()))
    if s[1] == "likes":
        s[2] = s[2][:len(s[2])-2]
    else:
        s[3] = s[3][:len(s[3])-2]
    d.append(s)
dic ={}
for i in d:    
    dic[i[0]] = 0
    if i[1] == "likes":
        dic[i[2]] = 0
    else:
        dic[i[3]] = 0
if a in dic:
    dic.pop(a)
for i in d:
    if a in i:
        if i[1] == "likes":
            if i[0]== a:
                dic[i[2]]+=5
            else:
                dic[i[0]]+=5
        elif i[2] == "commented":
            if i[0]== a:
                dic[i[3]]+=10
            else:
                dic[i[0]]+=10
        else:
            if i[0]== a:
                dic[i[3]]+=15
            else:
                dic[i[0]]+=15
res = []
for i in dic:
    res.append([dic[i], i])
res = sorted(res, reverse = True)
c = []
for i in range(len(res)-1):
    if res[i][0]>res[i+1][0]:
        print(res[i][1])
        c.sort()
        for i in c:
            print(i)
        c = []
    else:
        c.append(res[i][1])
c.append(res[len(res)-1][1])
c.sort()
for i in c:
    print(i)
