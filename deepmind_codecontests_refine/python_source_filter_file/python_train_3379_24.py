def solve(n, a):
    return "I becomoe the guy." if len(sorted(list(set(a)))) == n else "Oh, my keyboard!"


def main():
    n = int(input()) 
    a = list(map(int, input().split()))
    a.extend(list(map(int, input().split())))
    print(solve(n, a))


main()
