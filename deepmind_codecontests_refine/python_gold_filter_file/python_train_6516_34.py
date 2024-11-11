n = int(input())
#n, m = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
a = 'aabb'
s = ''
for i in range(n):
    s += a[i % 4]
print(s)