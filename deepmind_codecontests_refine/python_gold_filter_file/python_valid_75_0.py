for t in range(int(input())):
    k_a = list()
    k = list()
    a = list()
    power_needed = list()
    power_got = list()
    min_p = list()
    for i in range(int(input())): #n
        ka = [int(ka) for ka in input().split()]
        k_a.append(ka)
        k.append(ka[0])
        a.append(ka[1:])
        ps_needed = max([p-id+1 for id,p in enumerate(a[i])])
        power_needed.append(ps_needed)
        power_got.append(len(a[i]))
        min_p.append((power_needed[i], power_got[i]))
       
    sorted_min_p = sorted(min_p)
 
    max_p_needed = 0
    pre_power = 0
    for p,q in sorted_min_p:
        if p-pre_power > max_p_needed:
            max_p_needed = p-pre_power
        pre_power += q
    print(max_p_needed)