n=int(input())
l = [int(_) for _ in input().split()]
print('Yes' if max(l)<sum(l)-max(l) else 'No')