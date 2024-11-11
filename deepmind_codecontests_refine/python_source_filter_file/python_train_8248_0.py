t = int(input())
for _ in range(t):
    size = int(input())
    li = list(map(int,input().split()))
    flag = False
    for i in range(1,max(li)+1):
        s = []
        for j in li:
            s.append(j^i)
        if set(s) == set(li):
            flag = True
            print(i)
            break
    if( not flag):
        print(-1)

