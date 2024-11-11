Read = lambda : map(int, input().split())

n,m = Read()
s = set()
for i in range(n):
    s.add(int(''.join(map(str, input().split())), 2))
print(s)
for i in s:
    for j in s:
        if i&j==0:
            print('Yes')
            exit()
print('No')