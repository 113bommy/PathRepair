t = int(input())
for _  in range(t):
    l = int(input())
    s = str(input())
    if s.count("A") == 0 or s.count("P") == 0:
        print(0)
        continue
    big = c =  0
    pre = -1
    for i in range(-1,-l-1,-1):
        if  s[i] == "A":
            c= i-pre
            pre = i
            if  c < big:
                big = c
    print(-big )
