n, m = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
save = []
for i in a:
    mx = -(10 ** 19)
    for j in b:
        mx = max(mx, i * j)
    save.append(mx)
save = sorted(save)
##print(save)
print(save[-2])
        
