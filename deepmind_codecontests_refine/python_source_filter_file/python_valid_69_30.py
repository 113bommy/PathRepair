from sys import stdin, stdout
ip = lambda : stdin.readline().rstrip("\r\n")
ips = lambda : ip().split()
out = lambda x, end='\n': stdout.write(str(x)+end)
a = ['1']
x = 1
for i in range(50):
    x *= 2
    a.append(str(x))

for _ in range(int(input())):
    n = input()
    count = []
    for x in a:
        i = j = c = 0
        while i<len(n) and j<len(x):
            if n[i] == x[j]:
                j += 1
            else:
                c += 1
            i += 1
        c += len(x)-j+len(n)-i
        count.append(c)
    print(min(count))