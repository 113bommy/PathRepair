""" Codeforces Round #129 (Div. 2) | A - Little Elephant and Rozdil """
try:
    n = int(input())
    l = list(map(int, input().split()))

    index, min, f = 0, 1000000000, False
    for i in range(n):
        if l[i] < min:
            index = i
            min = l[i]
            f = False
        elif l[i] == min:
            f = True

    ans = str(index + 1) if f == False else 'Still Rozdil'
    print(ans)
except EOFError as e:
    pass
