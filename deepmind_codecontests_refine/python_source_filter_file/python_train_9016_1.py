n,k,m = [int(i) for i in input().split()]

l = [int(i) for i in input().split(" ")]
s = [[] for i in range(m)]

for i in l:
    s[i%m].append(i)

for i in range(m):
    if len(s[i])>k:
        print("Yes")
        print(*s[i][:k])
        exit(0)
print("No")