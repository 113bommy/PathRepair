n = int(input())
a = input()
s = set(a)
if len(s) == len(a):
    print('YES')
    exit()
for i in s:
    if a.count(i) > 1:
        print('YES')
        exit()
print('NO')









