n=int(input())
a=[*map(int,input().split())]
i=a.index(n)
print('YNEOS'[a!=sorted(a[:i])+sorted(a[i:])[::-1]::2])