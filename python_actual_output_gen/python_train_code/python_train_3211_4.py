n = int(input())
ans1, ans2 = 1, 1
data1 = list(map(int, input().split()))
data2 = list(map(int, input().split()))
for i in range(n):
    ans1 = ans1 | data1[i]
    ans2 = ans2 | data2[i]
print(ans1 + ans2)