n = int(input())
s = [int(i) for i in input().split()]
k = sum(s)//n
c = 0
for i in range(0,len(s)-1):
    if s[i] == k :
        continue
    need = k-s[i]
    s[i+1] -= need
    c += need
print(c)