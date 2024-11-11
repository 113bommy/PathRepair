n = int(input())
a = []
ans = []
for i in range(101):
    a.append(0)
for i in range(n):
    s1 = input().split()
    for i in range(1,len(s1),+1):
        a[int(s1[i])] += 1
for i in range(101):
    if a[i] == n:
        ans.append(i)
for i in range(len(ans)):
    print(ans[i])