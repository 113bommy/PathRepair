N = int(input())
An = list(map(int, input().split()))
odd = sum([1 for a in An if a % 2 != 0])
print(3**N - 2**odd)
