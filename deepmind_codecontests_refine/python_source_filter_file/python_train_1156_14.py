from collections import defaultdict
i = 2
n = int(input())
dic = defaultdict(lambda : 0)
while n > 1:
    if n%i == 0:
        n//=i
        dic[i]+=1
    else:i+=1
arr = list(dic.values())
ln = len(arr)
ans = [1, 0]
for el in dic.keys():ans[0]*=el
temp = 0
while True:
    onc = 0
    for i in range(ln):
        if arr[i]==1:onc+=1
        if arr[i]%2==1:
            arr[i]+=1
            temp += 1
        arr[i]//=2
    if onc==ln:break
    ans[1]+= 1
ans[1] += (1 if temp > 0 and ans[1]>0 else 0)
print(*ans)

