s = input()
dic={}
for i in ['n','e','i','t']:
    dic[i] = s.count(i)
ans = min(dic['t'],dic['i'])
ans = min((dic['n']-1)//2,ans)
ans = min(ans,dic['e']//3)
print(max(0,ans))
