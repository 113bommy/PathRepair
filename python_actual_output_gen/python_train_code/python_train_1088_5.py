for _ in range(int(input())):
    s = list(input())
    print(-1 if s[1]==s[:-1] else ''.join(map(str, sorted(s))))