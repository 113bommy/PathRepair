n , k = map(int,input().split())
arr = set(map(int,input().split()))

res = []

i = 1
while k > i :
    if i not in arr :
        res.append(i)
        k -= i
        arr.add(i)
    #print(i)
    i +=1

print(len(res))
print(*res)


