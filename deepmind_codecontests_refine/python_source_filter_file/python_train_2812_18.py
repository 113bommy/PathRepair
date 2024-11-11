from collections import Counter

def main():
    N = int(input())
    S = tuple(map(int, input().split()))
    Q = int(input())
    T = tuple(map(int, input().split()))

    counter = Counter(S)
    cnt = 0
    for i in T:
        cnt += counter[i]
    print(cnt)

main()

