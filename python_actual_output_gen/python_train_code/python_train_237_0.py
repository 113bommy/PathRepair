q = input()

n = [int(x) for x in input().split()]

p = input()

m = [int(x) for x in input().split()]

maximum = -1
ans = 0
for i in range(len(n)):
    for j in range(len(m)):
        if m[j] % n[i] == 0:
            print(m[j], n[i])
            div = m[j]/n[i]

            if maximum == div:
                # print(ans)
                ans += 1
            elif div < maximum:
                continue
            else:
                maximum = max(maximum, div)
                # print(ans)
                ans = 1


print(ans)
