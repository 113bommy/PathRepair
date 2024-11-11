def ans(n,g,gset):
    ans = 10000000000000000000000000
    gar = None
    for v in gset:
        count = 0
        for i in range(0,n - (n%3),3):
            if g[i] != v[0]:
                count+=1
            if g[i+1] != v[1]:
                count+=1
            if g[i+2] != v[2]:
                count+=1

        if n%3 != 0:
            r = n%3
            for i in range(r):
                if v[i] != g[len(g)-1-i]:
                    count+=1
        if count<ans:
            ans = count
            gar = v
    return [ans,gar]
n = int(input())
g = input()
gset = ['GRB','GBR','RGB','RBG','BGR','BRG']
res = ans(n,g,gset)
print(res[0])
gar = res[1]*(n//3)
if n % 3 != 0:
    mod = n%3
    ext = res[1][0:mod]
    gar+=ext
print(gar)