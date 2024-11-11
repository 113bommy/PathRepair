N = int(input())

S1 = input()
S2 = input()
MOD = 1000000007

if S1[0] == S2[0]:
    ans = 3
    pre = 1
else:
    ans = 6
    pre = 2
for i in range(1, N):
    if S1[i] == S1[i - 1]: continue
    if S1[i] == S2[i]:
        if pre == 1:
            ans *= 2
        pre = 1
    else:
        if ans==1:
            ans *= 2
        else:
            ans *=3
        pre = 2
    ans %= MOD
print(ans)
