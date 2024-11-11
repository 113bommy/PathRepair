n = int(input())
x = input()
one_num = x.count('1')

ans_reduce,ans_add = 0,0
for i in range(n):
    if(one_num>1):
        ans_reduce = (ans_reduce+pow(2,n-i-1,one_num-1)*(1 if x[i] == '1' else 0))%(one_num-1)
    ans_add = (ans_add+pow(2,n-i-1,one_num+1)*(1 if x[i] == '1' else 0))%(1+one_num)

for i in range(n):
    now_one = one_num + (-1 if x[i] == '1' else 1)
    if(now_one == 0):
        print(1)
        continue
    num = ((ans_reduce if x[i] == '1' else ans_add) + pow(2,n-i-1,now_one)*(-1 if x[i] == '1' else 1))%now_one
    ans = 1
    while(num!=0):
        ans += 1
        num = num % bin(num).count('1')
    print(ans)
