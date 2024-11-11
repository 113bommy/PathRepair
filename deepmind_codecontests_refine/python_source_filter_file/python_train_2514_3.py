_ = input()
s = input()
f = list(map(int, input().split()))
output = ""
out = False
start = 0
end = len(s)
for i in range(len(s)):
    x = int(s[i])
    if x < f[x-1]:
        start = i
        output += str(f[x-1])
        for j in range(i+1, len(s)):
            x = int(s[j])
            if x < f[x-1]:
                output += str(f[x-1])
            else:
                end = j
                break
        out = True
    if out:
        break
if not out:
    print(s)
else:
    print(s[:start] + output + s[end:])