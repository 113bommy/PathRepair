t = int(input())
for _ in range(t):
    # s = input()
    # q = int(input())
    # w = list(map(int,input().split()))
    # d = -1
    # j = []
    # counts = 0
    # for i in range(len(s)-1):
    #     if s[i] == "(" and s[i+1] == ")":
    #       j.append(i)
    #       counts += 1
    # for k in j:
    #     if s[k] and k != 0:
    a = list(map(int,input().split()))
    s = set(a)
    if len(s) == 1:
        print("YES")
        print(a[0],a[0],a[0])
    elif len(s) == 2:
        if a.count(max(a)) == 2:
            print("YES")
            print(max(a), min(a), min(a) -1 )
        else:
            print("NO")
    else:
        print("NO")