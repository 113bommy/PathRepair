t = int(input())
ans = []
for iter in range(t):
    length = int(input())
    seen = []
    s = input().split(" ")
    for x in s:
        if x not in seen:
            seen.append(x)
    ans.append(seen)
for x in seen:
    s = ""
    for i in range(len(x)):
        if i != len(x)-1:
            s += x[i] + " "
        else:
            s += x[i]
    print(s)
