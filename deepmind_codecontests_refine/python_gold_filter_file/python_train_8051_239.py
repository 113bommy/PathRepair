n = int(input())
l = input().split()
m = 0
for j in range(n):
    m += int(l[j])
print(format(m/n,'.12f'))