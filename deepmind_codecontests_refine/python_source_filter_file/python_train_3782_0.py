from collections import Counter
t = int(input())

for _ in range(t):
    n,m = map(int,input().split())

    strings = []

    for i in range(n):
        strings.append(input())
    
    n_strings = []
    for i in range(n-1):
        n_strings.append(input())

    
    s = []
    s1 = []
    for i in range(m):
        k = ""
        for j in range(n):
            k+=strings[j][i]
        s.append(k)
    
    for i in range(m):
        k = ""
        for j in range(n-1):
            k+=n_strings[j][i]
        s1.append(k)

    res = []
    print(len(s),len(s1))
    for i in range(m):

        z= (Counter(s[i])-Counter(s1[i])).elements()
        # print(*z)
        # print(s[i],s1[i])
        res.append(str(*z))
    
    print("".join(res))