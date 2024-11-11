n = int(input())
s = input()
m = int(input())
print(*['*' if x != s[m-1] else x for x in s], sep='')