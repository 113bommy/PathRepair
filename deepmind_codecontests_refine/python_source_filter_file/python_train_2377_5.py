# でつoO(YOU PLAY WITH THE CARDS YOU'RE DEALT..)
import sys
def main(N, A, B):
    if A + B - 1 > N or A * B < N:
        print(-1)
        return
    P = []
    r = A * B - N
    for b in range(B):
        for a in range(A):
            if b >= 1 and a >= 1 and r > 0:
                if r >= A - 1:
                    r -= A - 1
                    break
                r -= 1
                continue
            P.append((B - b) * a + a + 1)
    s = sorted([(p, i) for i, p in enumerate(P)], key=lambda x: x[0])
    s = sorted([(i, j) for j, (p, i) in enumerate(s)], key=lambda x: x[0])
    s = [j + 1 for i, j in s]
    print(*s)

if __name__ == '__main__':
    input = sys.stdin.readline
    N, A, B = map(int, input().split())
    main(N, A, B)
