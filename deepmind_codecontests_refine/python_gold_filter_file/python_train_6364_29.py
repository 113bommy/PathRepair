
n = int(input())
a = [int(x) for x in input().split()]
ans = 100000
for i in range(1, 101):
    s = sum([abs(b-i) - 1*(b != i) for b in a])
    if s < ans:
        ans = s 
        t = i
print(t, ans)