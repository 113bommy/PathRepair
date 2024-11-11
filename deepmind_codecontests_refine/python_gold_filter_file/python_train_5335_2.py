n = int(input())
ans = []
for i in range(n):
    l = int(input())
    a = list(map(int, input().split()))
    alice_index = 0
    bob_index = len(a) - 1
    alice_cnt = 0
    bob_cnt = 0
    bob_tmp = 0
    cnt = 0

    if len(a) == 1:
        ans.append([1, a[0], 0])
        continue

    while alice_index <= bob_index:

        alice_tmp = 0
        onceA = 0
        while alice_tmp <= bob_tmp and alice_index <= bob_index:
            if not onceA:
                cnt += 1
                onceA = 1
            alice_cnt += a[alice_index]
            alice_tmp += a[alice_index]
            alice_index += 1

        bob_tmp = 0
        onceB = 0
        while bob_tmp <= alice_tmp and alice_index <= bob_index:
            if not onceB:
                cnt += 1
                onceB = 1
            bob_cnt += a[bob_index]
            bob_tmp += a[bob_index]
            bob_index -= 1

        # print(cnt, alice_cnt, bob_cnt)
    ans.append([cnt, alice_cnt, bob_cnt])

for i in range(n):
    print(*ans[i])
