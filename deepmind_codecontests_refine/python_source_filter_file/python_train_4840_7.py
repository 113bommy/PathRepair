n = int(input()) 
#n, m = map(int, input().split())
#s = input()
a = []
for i in range(1, n):
    c = list(map(int, input().split()))
    for j in range(n):
        if c[j] == 1 or c[j] == 3:
            break
    else:
        a.append(i)
print(len(a))
print(*a)