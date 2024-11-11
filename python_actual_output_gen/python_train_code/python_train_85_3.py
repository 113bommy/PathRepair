for _ in range(int(input())):
    n, m = map(int, input().split())
    s = input()
    p = list(map(int, input().split()))
    cnts = [0] * 26

    p.sort()
    index = 0
    for i, char in enumerate(s):
        while index < m and i > p[index] - 1:
            index += 1
        cnts[ord(char) - 97] += m - index + 1 if index != m else 1
    
    print(cnts)