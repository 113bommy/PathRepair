n =  int(input())
idi = list(map(int,input().split()))
idi.sort()
ans = (n > 2 and idi[0] == idi[1] and idi[0] != 0)
for i in range(2,n):
    if idi[i] == 0:
        continue
    ans += (idi[i] == idi[i-1])
    if idi[i] == idi[i-2]:
        ans = -1
        break
print(int(ans))
