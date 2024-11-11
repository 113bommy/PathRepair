n = int(input())
A = [int(i) for i in input().split(" ")]
B = [int(i) for i in input().split(" ")]
print('Yes') if sum(A)<=sum(B) else print('No')
