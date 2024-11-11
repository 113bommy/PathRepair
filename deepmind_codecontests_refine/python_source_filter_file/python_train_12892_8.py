N = int(input())
S1 = input()
S2 = input()

i = 1
if S1[0] == S2[0]:
    ans = 3
    state = 0
else:
    i+= 1
    ans = 6
    state = 1
mod  = 10**9 + 7
while N > i:
    if S1[i] != S2[i] and state == 0:
        ans *= 2
        i+=2
        state = 1
    elif S1[i] != S2[i] and state == 1:
        ans *= 3
        i+=2
    elif S1[i] == S2[i] and state == 0:
        ans *= 2
        i+= 1
    elif S1[i] == S2[i] and state == 1:
        ans *= 1
        i+=1
        state = 0

    ans %= mod
print(ans)
~
