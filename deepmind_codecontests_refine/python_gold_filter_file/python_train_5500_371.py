N = int(input())
A = int(input())
print('Yes' if N-(N//500)*500 <= A else 'No')