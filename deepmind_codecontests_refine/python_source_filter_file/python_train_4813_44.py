from functools import reduce

def factors(n):    
    return set(reduce(list.__add__, 
                ([i, n//i] for i in range(1, int(n**0.5) + 1) if n % i == 0)))

fac_dict = dict()
for i in range(1,10001):
    fac_dict[i] = factors(i)
    
t = int(input().strip())
for _ in range(t):
    a,b,c = map(int,input().strip().split())
    ans = 100000
    ans_list = [0,0,0]
    for i in range(max(1,c - 2500),min(10001,c + 2500)):
        for first_fac in fac_dict[i]:
            if abs(c - i) + abs(b - first_fac) > ans:
                continue
            for sec_fac in fac_dict[first_fac]:
                cost = abs(c - i) + abs(b - first_fac) + abs(a - sec_fac)
                if cost < ans:
                    ans = cost
                    ans_list[2] = i
                    ans_list[1] = first_fac
                    ans_list[0] = sec_fac
    print(ans)
    print(' '.join(str(i) for i in ans_list))
