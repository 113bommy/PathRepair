N = int(input())
A = sorted(list(map(int,input().split())))

p = A[-1]
n = A[0]

ans_list = []

for a in A[1:-1]:
    if a >= 0:
        ans_list.append((n, a))
        n -= a
    else:
        ans_list.append((p, a))
        p -= a

M = p - n
ans_list.append((p, n))

print(M)
for ans in ans_list:
    print(ans)