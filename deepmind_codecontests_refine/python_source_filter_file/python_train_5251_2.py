n, m, Min, Max = map(int, input().split())
t = list(map(int, input().split()))

if min(t) >= Min or max(t) <= Max:
    if m + abs(len({Min,Max} & set(t))-2) <= n:
        print('Correct')
    else:
        print('Incorrect')
else:
    print('Incorrect')