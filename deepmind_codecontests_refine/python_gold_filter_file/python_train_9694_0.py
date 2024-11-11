n = int(input())
t_11=[]
t_10=[]
t_01=[]
t_00=[]
for x in range(n):
    tmp=list(input().split())
    supp = str(tmp[0])
    m = int(tmp[1])
    t_tmp = [supp, m]
    if supp == '11':
        t_11.append(t_tmp)
    elif supp == '01':
        t_01.append(t_tmp)
    elif supp == '10':
        t_10.append(t_tmp)
    else:
        t_00.append(t_tmp)
t_00=sorted(t_00, key=lambda x: x[1])
t_10=sorted(t_10, key=lambda x: x[1])
t_01=sorted(t_01, key=lambda x: x[1])
t_11=sorted(t_11, key=lambda x: x[1])
pop_a = 0
pop_b = 0
tot_inf = 0
pop_tot=0
l_t_11 = len(t_11)-1
for x in range(l_t_11,-1,-1):
    pop_a+=1
    pop_b+=1
    pop_tot+=1
    tot_inf+=t_11[-1][1]
    del t_11[-1]
for x in range(min(len(t_10),len(t_01))-1,-1,-1):
    pop_b+=1
    pop_a+=1
    pop_tot+=2
    tot_inf+=t_01[-1][1]+t_10[-1][1]
    del t_01[-1]
    del t_10[-1]
tmp_inf_1 = 0
tmp_inf_2 = 0
tmp_inf_3 = 0
tmp_t1 = []
tmp_t2 = []
if len(t_10)!=0:
    for x in t_10:
        tmp_t1.append(x)
    for x in t_00:
        tmp_t1.append(x)
    tmp_t1 = sorted(tmp_t1, key=lambda x: x[1])
    while True:
        if len(tmp_t1)==0 or pop_a*2==pop_tot or pop_b*2==pop_a or pop_b*2==pop_tot:
            break
        tot_inf+=tmp_t1[-1][1]
        if tmp_t1[-1][0] == '10':
            pop_a+=1
            pop_tot+=1
        else:
            pop_tot+=1
        del tmp_t1[-1]
    print(tot_inf)
elif len(t_01)!=0:
    for x in t_01:
        tmp_t2.append(x)
    for x in t_00:
        tmp_t2.append(x)
    tmp_t2 = sorted(tmp_t2, key=lambda x: x[1])
    while True:
        if len(tmp_t2)==0 or pop_b*2==pop_tot or pop_a*2==pop_b or pop_a*2==pop_tot:
            break
        tot_inf+=tmp_t2[-1][1]
        if tmp_t2[-1][0] == '01':
            pop_b+=1
            pop_tot+=1
        else:
            pop_tot+=1
        del tmp_t2[-1]
    print(tot_inf)
else:
    if len(t_00)==0:
        print(tot_inf)
        exit(0)
    else:
        while True:
            if len(t_00)==0 or pop_a*2==pop_tot or pop_b*2==pop_tot:
                break
            tot_inf+=t_00[-1][1]
            pop_tot+=1
            del t_00[-1]
        print(tot_inf)