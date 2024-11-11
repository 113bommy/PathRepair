def can_buy(x):
    return sum(x) % 2 == 0

def solution(x):
    t = []
    for k in range(len(x)):
        if x[k] != 0:
            t.append(x[k])
        else:
            if len(t) > 0 and not can_buy(t):
                return 'NO'
            t = []
    return 'YES'


N = int(input())
x = list(map(int, input().split()))

print(solution(x))