n=int(input())
a=[i for i in input().split()]

print('YES' if len(set(a)==n) else 'NO')