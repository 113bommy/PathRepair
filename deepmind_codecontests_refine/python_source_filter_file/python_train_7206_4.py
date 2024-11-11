T=(int(input()))
for i in range(0,T):
    ls = list(map(int, input().split()))
    w1 = max(ls[1]-ls[3], ls[3])
    l1 = max(ls[0]-ls[2], ls[2])
    print(max(w1*ls[0], l1*ls[1]))