n = int(input())
l = [int(x) for x in  input().split()]
c = 0
for i in range(n - 1, -1, -1):
        if(n > i):
            c += 1
        n = min(i, i - l[i])
        # print('n =', n)
print(c)  