n,k=map(int,input().split())
s=input()

list10 = {'0':[],'1':[]}
pre_c='1'
c_c = 0
cur_sum = 0
cur_max = 0
for c in s:
    if c==pre_c:
        c_c += 1
    else:
        list10[pre_c].append(c_c)
        cur_sum += c_c
        c_c = 1
        pre_c = c
    if len(list10['1'])== k+1:
        cur_max = max(cur_max,cur_sum)
        cur_sum -= (list10['0'].pop() + list10['1'].pop())
print(max(cur_max,cur_sum+c_c))