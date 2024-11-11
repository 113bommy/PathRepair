t = int(input())
while t:
    t-= 1
    n = int(input())
    ls = list(map(int, input().split()))
    flag = 0
    for i in range(len(ls)-2):
        if ls[i]+ls[i+1]<=ls[i+2]:
            print(i+1, i+2, i+3)
            flag = 1
            break
    if flag == 0:
        print(-1)