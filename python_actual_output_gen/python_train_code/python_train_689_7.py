s = list(input())
ans = [sum(map(int, s)), 9*(len(s)-1) + int(s[0]-1)]
print(max(ans))