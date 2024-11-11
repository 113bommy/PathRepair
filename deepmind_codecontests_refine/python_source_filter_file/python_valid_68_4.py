t = int(input())
cases = []
for i in range(t):
    cases.append(int(input()))


def answer(n):
    sqr = (int(n**0.5)+1)**2
    rt = int(sqr**0.5)
    diff = n-(rt-1)**2
    if diff == 0:
        return(rt, 1)
    if diff <= rt:
        return(diff, rt)
    else:
        return (rt, 2*rt - diff)

for i in cases:
    print(*answer(i))

