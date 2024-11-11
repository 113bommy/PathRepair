s = input()
n = int(input())
a = list(map(int,input().split()))
res = 0
for i in range(len(s)):
    res += (i + 1)*a[ord(s[i])-ord('a')]
mul = n * (n + len(s) + len(s) + 1)//2
print(res + mul*max(a))