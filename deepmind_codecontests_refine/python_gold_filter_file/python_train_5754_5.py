from sys import stdin, stdout


t = int(stdin.readline())
for _ in range(t):
    n, k, z = map(int, stdin.readline().split())
    a_a = list(map(int, stdin.readline().split()))

    preSum = [0]
    for i in range(len(a_a)):
        preSum.append(a_a[i] + preSum[i])

    #print(preSum)

    ans = a_a[0]
    for i in range(1, len(a_a)):
        move = k
        score = preSum[i+1]
        #print(score)
        move -= i
        if move == 0:
            ans = max(ans, score)
            break

        if move < 2*z:
            score += a_a[i] * (move // 2)
            score += a_a[i-1] * (move // 2 + move % 2)
        else:
            score += (a_a[i] + a_a[i-1]) * z
            move -= 2*z
            score += preSum[min(i + move + 1, len(a_a))] - preSum[i+1]

        #print(score)
        #print("---------")

        ans = max(ans, score)

    stdout.write(str(ans) + '\n')
