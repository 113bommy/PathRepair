n = int(input())
string = input().strip()
ans = string[0]
vols = {'a','e','i','o','u'}
for i in range(1, n):
    if ans[-1] in vols:
        if string[i] in vols:
            continue
    ans += string[i]
print(ans)