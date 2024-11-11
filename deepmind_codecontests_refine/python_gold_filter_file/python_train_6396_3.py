n, k, x = map(int,input().split())
a = list(map(int,input().split()))
ans = 0
for i in range(n+1):
    b = a[:i] + [x] + a[i:]+[-1]
    for j in range(123):
        #print(b)
        c = 1
        for j in range(1, len(b)):
            #print(j)
            if b[j] == b[j - 1]:
                c += 1
            else:
                if c >= 3:
                    b = b[:(j - c)] + b[j:]
                    break
                c = 1
    #print(b)
    #print()
    ans = max(len(a) - len(b) + 1, ans)
print(ans)