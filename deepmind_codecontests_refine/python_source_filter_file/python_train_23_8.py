def func(n, k):
    common = []
    bob = []
    alice = []
    for i in range(n):
        t, a, b = map(int, input().split())
        if a and b:
            common.append(t)
        elif a:
            alice.append(t)
        else:
            bob.append(t)

    if len(common)+len(alice) < k or len(common)+len(bob) < k:
        print(-1)
        return

    common.sort()
    alice.sort()
    bob.sort()

    c_num = min(k, len(common))
    num = k-c_num

    while c_num != 0 and num < len(alice) and num < len(bob) and common[c_num-1] > alice[num]+bob[num]:
        c_num -= 1
        num += 1
    print(sum(common[:c_num])+sum(alice[:num])+sum(bob[:num]))


# cases = int(input())
for i in range(1):
    n, k = map(int, input().split())
    func(n, k)
