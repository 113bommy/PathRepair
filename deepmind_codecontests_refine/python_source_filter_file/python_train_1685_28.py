for _ in range(int(input())):
    n = int(input())
    l1 = [int(__) for __ in input().split()]
    l1.reverse()
    shit = l1[0]
    ans = 0
    for i in l1[1:]:
        if i < shit:
            shit = i
        else:
            ans += 1
    print(ans)
