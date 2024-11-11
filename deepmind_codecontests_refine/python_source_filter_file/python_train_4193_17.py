t = int(input())
while t:
    t -=1
    n,p = map(int,input().split())
    count = 0
    l = [[i for i in input()] for j in range(n)]
    for i in range(n):
        s = l[i]
        if i != n-1:
            if s[-1]=="R":
                count+=1
        else:
            count+= s.count("D")

    if n == 1:
        count += s.count("D")
    # elif p == 1:
    #     for i in range(n):
    #         if s[1] == "R":
    #             count +=1
    print(count)
