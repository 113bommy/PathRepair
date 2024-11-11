n = int(input())
#n, m = map(int, input().split())
#s = input()
#c = list(map(int, input().split()))
a = 'aabc'
s = ''
for i in range(n):
    s += a[i % 4]
print(s)