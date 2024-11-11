n =int(input())
s = input()
s = list(s)
for i in range(len(s)):
    if s[i] =='o':
        s[i] = int(1)
    else:
        s[i] = int(-1)

syoki_list = [[1,1],[1,-1],[-1,1],[-1,-1]]
a = "-1"
for i in range(len(syoki_list)):
    t = []
    t.append(syoki_list[i][0])
    t.append(syoki_list[i][1])
    for j in range(2,n+1):
        t.append(t[j-2] * t[j-1] * s[j-1])
    if t[0] ==t[n] and t[1] == t[n] * t[0]*s[0]:
        for i in range(n+1):
            if t[i] == 1:
                t[i] = "S"
            else:
                t[i] = "W"
        a= "".join(t[:n])
        break

print(a)