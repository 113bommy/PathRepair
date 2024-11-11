k = int (input())
a = input()
a = a.split()
a = list(int(a[i]) for i in range(len(a)))
for i in range(len(a)):
    for j in range(len(a)-i-1):
        if a[j] < a[j+1]:
            t = a[j]
            a[j] = a[j+1]
            a[j+1] = t
sum = 0
if(k == 0):
    print(-1)
else :
    for i in range(len(a)):
        sum = sum + a[i]
        if(sum >= k):
            print(i+1)
            break
if(sum < k):
    print(-1)
