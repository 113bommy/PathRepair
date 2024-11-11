n=int(input())
s=list(map(int,input().split()))
print('YES' if len(set(s))==n else 'NO')