T = int(input())
for _ in range(T):
    num = int(input())
    s = sorted(list(map(int,input().split())))
    s = s[::-1]
    for i in range(max(s),0,-1):
        count = 0
        for j in s:
            if j>=i:
                count +=1
        if count >= i:
            print(i)
            break