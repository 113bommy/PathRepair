n, t1, t2, k = [int(i) for i in input().split()]

ans = []

for i in range(n):
    
    v, u = [int(i) for i in input().split()]
    
    h = max(v*t1*(100 - k)/100 + u*t2, u*t1*(100 - k)/100 + v*t2)
    ans.append((i, h))
    
ans.sort(key = lambda x : (x[1], x[0]) , reverse = True)

for i, h in ans:
    print(i+1, "{0:.2f}".format(h))