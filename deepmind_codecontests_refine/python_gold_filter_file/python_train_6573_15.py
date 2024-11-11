_ = input()
n, k = _.split()
n, k = int(n), int(k)
a = input()
_a = a.split()
a = [0] * k
for i in _a:
    num = int(i)
    a[num%k] = a[num%k] + 1

answer = (a[0] // 2)*2
for i in range(1,(k-1)//2+1):

    answer = answer + min(a[i],a[k-i])*2
if k % 2 == 0:
    answer = answer + (a[k//2]//2)*2

print(answer)