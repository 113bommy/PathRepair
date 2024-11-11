I = lambda: list(map(int, input().split()))
s = input()
for i in range(1, len(s)):
    if s[:i]*(len(s)//i)==s:
        print(i)
        quit()
print(len(s))