n = int(input())
s = input()
for i in range(n):
    if n%(i+1) == 0:
        s = s[:i+1][::-1] + s[i+1:]
        print(s)