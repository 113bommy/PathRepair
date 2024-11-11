n = int(input())
s = input()
subs = s[:n-10]
if subs.count("8") > (n-11)/2:
    print('YES')
else:
    print('NO')