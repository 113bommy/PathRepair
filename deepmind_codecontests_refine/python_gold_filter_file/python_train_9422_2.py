n = int(input())
l = list(map(int, input().split()))
l2 = [0]*len(l)
for i in range(len(l)):
    l2[l[i]-1] = i
prev = -1
ans = -1e9
curr = 0
for i in l2:
    if i>prev:
        curr+=1
        prev = i
    else:
        ans = max(curr, ans)
        curr = 1
    prev=i
print(n-max(curr, ans))
