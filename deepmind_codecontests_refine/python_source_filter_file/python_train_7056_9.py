s = input()
T = ""
n = int(input())
for i in range(n):
    # print(s,T)
    t = list(map(str,input().split()))
    if t[0] == "1":
        s,T = T,s
    else:
        if t[1] == "1":
            s += t[2]
        else:
            T += t[2]

print(T+s[::-1])