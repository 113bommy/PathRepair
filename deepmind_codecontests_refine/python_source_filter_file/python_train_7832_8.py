import sys
input = sys.stdin.readline


answer = []
for kek in range(int(input())):
    n = int(input())
    p = list(map(int, input().split()))
    ans = [p[0]]
    flag = True
    if p[1] > p[0]:
        flag = True
    else:
        flag = False

    for i in range(1, n):
        if flag:
            if p[i] > p[i-1]:
                continue
            else:
                flag = False
                ans.append(p[i-1])
        else:
            if p[i] < p[i-1]:
                continue
            else:
                flag = True
                ans.append(i-1)
    if ans[-1] != p[-1]:
        ans.append(p[-1])
    answer.append(ans)

for i in answer:
    print(len(i))
    print(*i)