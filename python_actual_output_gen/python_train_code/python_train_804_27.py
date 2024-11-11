n = int(input())
numbers = list(map(int, input().split()))
print(2 + numbers[2] ^ min(numbers))