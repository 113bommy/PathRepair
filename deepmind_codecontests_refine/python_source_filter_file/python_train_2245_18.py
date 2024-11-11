n, m = map(int, input().split())
a = list(input())
place = a[min(a.index("G"), a.index("T") + 1): max(a.index("T"), a.index("G")+1): m]
print('NO' if '#' in place or 'T' not in place or 'G' not in place else 'YES')