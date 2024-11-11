def solution(l):
    if l[1] - l[0] > 2:
        return 1
    return 0


if __name__ == '__main__':
    n = int(input())
    count = 0
    for i in range(n):
        s = input()
        l = list(map(int, s.split()))
        count += solution(l)
    print(count)
