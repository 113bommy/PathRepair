for _ in range(int(input())):
    lens = int(input())
    vals =  sorted([int(x) for x in input().split()])
    ans  = 1
    for i in range(lens - 1):
        if abs(vals[i] - vals[i+1]) > 1:
            ans = 2
            break
    print(ans)