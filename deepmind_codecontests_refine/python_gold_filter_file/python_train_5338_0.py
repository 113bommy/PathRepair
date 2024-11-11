n = int(input())
a = list(map(int,input().split()))
a = sorted(a)
i = 0
j = n-1
cnt = 0
l = []
while(i<=j):
    l.append(a[j])
    j -= 1
    if(i < j):
        l.append(a[i])
        i += 1

for i in range(1,len(l)-1):
    if(l[i] < l[i-1] and l[i] < l[i+1]):
        cnt += 1
print(cnt)
print(*l)
