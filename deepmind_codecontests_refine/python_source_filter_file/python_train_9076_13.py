for __ in range(int(input())):
    a = list(input())
    A = dict()
    ans = set()
    A[a[0]] = 1
    for i in range(1, len(a)):
        if a[i] != a[i - 1]:
            A[a[i]] = 1
            if A[a[i - 1]] % 2 == 1:
                ans.add(a[i - 1])
        else:
            A[a[i]] += 1
    if A[a[-1]] % 2 == 1:
        ans.add(a[-1])
    ans1 = list(ans)
    ans1.sort()
    print(''.join(ans))