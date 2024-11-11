x, y = list(map(int, input().strip().split()))
ans = 0
li = [0]
val = list(map(int, input().strip().split()))
res = [sum(val[ :i]) for i in range(1,len(val)+1)] #prefix sum
li.extend(res)
i = 0
while i < y:
    num_1, num_2 = list(map(int, input().strip().split()))
    i += 1

    
    store = li[num_2] - li[num_1-1]
    if store >= 0:
        ans = ans + store
print(ans)
    
    
    
