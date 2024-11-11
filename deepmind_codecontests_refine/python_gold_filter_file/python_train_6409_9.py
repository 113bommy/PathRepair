n,m,k = [int(i) for i in input().split()]
x,s = [int(i) for i in input().split()]
a_t = [int(i) for i in input().split()]
a_m = [int(i) for i in input().split()]
b_p = [int(i) for i in input().split()]
b_m = [int(i) for i in input().split()]

min_time = n * x

a_t.append(x)
a_m.append(0)

for i in range(m+1):
    re_mana = s - a_m[i]
    if re_mana < 0:
        continue
    inf = -1
    sup = k
    while inf<sup-1:
        #print(inf,sup)
        mid = (inf+sup)//2
        if b_m[mid] <= re_mana:
            inf = mid
        else:
            sup = mid 
    if inf<=-1:
        min_time = min(min_time,n*a_t[i])
    else:
        min_time = min(min_time,max(0,n-b_p[inf])*a_t[i])



print(min_time)
