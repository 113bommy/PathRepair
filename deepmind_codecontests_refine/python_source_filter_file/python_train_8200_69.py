n=int(input())
a=list(map(int, input().split()))
print('Yes' if len(set(a))==n else 'No')