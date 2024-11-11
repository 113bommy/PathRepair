def Input():
    tem = input().split()
    ans = []
    for it in tem:
        ans.append(int(it))
    return ans

n = Input()[0]
a = Input()
l_or = [0 for i in range(n)]
tem = 0
for i in range(n):
    l_or[i] = (tem|a[i])
    tem = l_or[i]
inx = -1
MAX = 0
tem = 0
for i in range(n-1,-1,-1):
    if i-1>=0:
        mean = a[i] - (a[i]&(l_or[i-1]|tem))
    else:
        mean = a[i] - (a[i]&tem)
    if mean>MAX:
        MAX = mean
        inx = i
    tem = (tem|a[i])
# inx = 2
# tem = a[inx]
# for i in range(n):
#     if i==inx:
#         continue
#     tem = (tem|a[i])-a[i]
# print(tem)
    
print(a[inx],end='')
for i in range(n):
    if i==inx:
        continue
    print('',a[i],end='')
print()

    