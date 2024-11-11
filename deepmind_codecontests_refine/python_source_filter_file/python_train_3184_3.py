def main():
    start, end, t = map(int, input().split())
    n = int(input())
    people = []
    if n != 0:
        people = list(map(int, input().split()))
    time = start
    ans = 1e9
    answer = 0
    for p in people:
        if p + t > end:
            break
        if p - 1 >= 0:
            if ans > max(0, time - (p - 1)):
                ans = max(0, time - (p - 1))
                answer = p - 1

        time = max(time, p) + t

        if time + t > end:
            break

    if time + t <= end:
        answer = time
    print(answer)

main()