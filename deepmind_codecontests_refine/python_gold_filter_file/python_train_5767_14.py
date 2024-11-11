t,x,y,u,v = map(int,input().split())
dic = {}
dic['N'],dic['S'] = (v-y,0) if v>=y else (0,y-v)
dic['E'],dic['W'] = (u-x,0) if u>=x else (0,x-u)
inp = str(input())
for i in range(t):
    dic[inp[i]]-=1
    if dic['N']<1 and dic['S'] < 1 and dic['E'] < 1 and dic['W'] < 1:
        print (i+1)
        break
else:
    print (-1)