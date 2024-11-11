N = int(input())
a = list(map(int, input().split()))
s = sorted(a)
print(sum(s[N:2*N]))
