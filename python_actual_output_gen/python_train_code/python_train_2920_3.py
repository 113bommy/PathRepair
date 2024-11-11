def foo(n,k,t):
    l = list()
    progress = (t*n*k)/100
    ai = int(progress/k)
    for i in range(ai):
        l.append(k)
    m = progress%k
    if m<1: m=0
    if n > ai:
        l.append(round(m))
    for i in range(ai+1, n):
        l.append(0)
    print(*l)
if __name__ == '__main__':
    n = [int(x) for x in input().split()]
    foo(n[0], n[1], n[2])