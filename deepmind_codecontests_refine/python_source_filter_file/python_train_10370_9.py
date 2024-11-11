import sys
N,K = map(int,input().split())
a_ls = list(map(int, input().split()))

co = 0
total = 0
for i in range(N):
    if a_ls[i] == 8:
        total += 8
    elif a_ls[i] > 8:
        co += 8-a_ls[i]
        total += 8
    else:
        lack = 8-a_ls[i]
        if co >= lack:
            total += 8
            co -= lack
        else:
            total += a_ls[i] + co
            co = 0
    if total >= K:
        print(i+1)
        sys.exit()
print(-1)