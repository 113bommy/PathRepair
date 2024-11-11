n = int(input())
a = [int(input()) for i in range(n)]
a2 = sorted(set(a), reverse = True)
for i in a:
    print(a2[0] if i!=a2[0] else a2[1])