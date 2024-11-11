def solve(n):
    return [i for i in range(1, n+1)]

if __name__ == '__main__':
    ans = []
    for _ in range(int(input())):
        ans.append(solve(int(input())))
    for a in ans:
        print(*a)





