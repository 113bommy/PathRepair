n,m,d = map(int,input().strip().split())
cs = [int(i) for i in input().strip().split()]
river = [0 for i in range(n + 2)]
stand = 0;p_index = 0;out = False
while p_index < len(cs):
    if stand + d > n:
        p_index -= 1
        break
    for i in range(stand + d,stand + d + cs[p_index]):
        if i > n:
            out = True
            break
        river[i] = p_index + 1
        stand = i
    if out:
        p_index -= 1
        break
    p_index += 1

if stand + d <= n:
    print('no')
else:
    pops = [i for i in range(p_index + 1, len(cs))]
    #print(pops)
    a_index = n
    i = len(cs) - 1
    if p_index == -1:
        i = 0
        a = 1
        while i < len(cs):
            for j in range(a,a + cs[i]):
                river[j] = i + 1
            
            a += cs[i]
            i += 1
    else:
        #print(river[1:-1],p_index)
        need = False
        while pops != []:
            to_pop = pops.pop()
            #print(to_pop)
            for j in range(a_index, a_index - cs[to_pop], -1):
                if river[j] != 0 and river[j] != i + 1:
                    if river[j] - 1 not in pops:
                        pops = [river[j] - 1] + pops
                river[j] = to_pop + 1
            a_index -= cs[to_pop]
           
            
    print('yes')
    print(' '.join(str(i) for i in river[1:-1]))
