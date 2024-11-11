n = int(input())
s = input()
res = 0
l1 = [1]
l2 = [1]
res = 0
for i in range(1,n):
    l1.append(l2[i-1]+1)
    l2.append(l2[i-1]+l1[i])
    if(s[i-1] == 'B'):
        res += l1[i-1]
#print(l1)
print(res)