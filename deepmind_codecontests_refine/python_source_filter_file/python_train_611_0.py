# coding: utf-8
M, N = list(map(int, input().split()))
q = int(input())

Map = []
for i in range(M):
    Map.append(input)

def get_slide_sum(Map, kw):
    l = []
    for r in range(M):
        tmp = []
        for c in range(N):
            ll = 0 if c == 0 else tmp[c-1]
            ul = 0 if r == 0 or c == 0 else l[r-1][c-1]
            ur = 0 if r == 0 else l[r-1][c]
            count = ll + ur - ul
            if Map[r][c] == kw:
                count+=1
            tmp.append(count)
        l.append(tmp)
    return l

J = get_slide_sum(Map, 'J')
O = get_slide_sum(Map, 'O')
I = get_slide_sum(Map, 'I')

def get_sum(inp,L):
    a, b, c, d = list(map(int, inp.split()))
    ll = 0 if a == 1 else L[a-2][d-1]
    ul = 0 if a == 1 or b == 1 else L[a-2][b-2]
    ur = 0 if b == 1 else L[c-1][b-2]
    return L[c-1][d-1] - ll - ur + ul

for i in range(q):
    inp = input()
    print(get_sum(inp, J), get_sum(inp, O), get_sum(inp, I))