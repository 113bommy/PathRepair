N = int(input())
inputs = [int(i) for i in input().split()]

inputs.sort()

print(sum(inputs[N::2]))