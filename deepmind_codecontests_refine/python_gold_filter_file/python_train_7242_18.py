#n = int(input())
#n, k, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
'''for i in range(n):
    c = list(map(int, input().split()))'''
b = list('Bulbasr')
a = [0] * 7
for i in range(len(s)):
    if s[i] in b:
        a[b.index(s[i])] += 1
a[1] //= 2
a[4] //= 2
l = min(a)
print(l)