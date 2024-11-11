N = int(input())
A = [int(input()) for _ in range(N)]

keta_count = [0] * 65
first_appear = [0] * 65

for a in A:
    i = 0
    while a:
        keta_count[i] += a % 2
        a //= 2
        i += 1

for a in A:
    i = 0
    
    while (a & (1<<(i+1) -1)) != 1<<i:
        i += 1
    first_appear[i] += 1


# print(keta_count)
# print(first_appear)

ans = 0
for i in range(64, -1, -1):
    if keta_count[i] % 2 != 0:

        if first_appear[i] > 0:
            first_appear[i] -= 1
            keta_count[i] -= 1
            ans += 1
            for i in range(0,i):
                keta_count[i] += 1
            first_appear[0] += 1
        else:
            print(-1)
            exit()

if keta_count[0] % 2 != 0:
    print(-1)
else:
    print(ans)

# print(keta_count)
# print(first_appear)
