n= int(input())
l = [int(x) for x in input().split()]
print('Yes' if max(l)<sum(l)-max(l) else 'No')