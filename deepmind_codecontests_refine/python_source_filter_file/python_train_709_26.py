N = int(input())
an = list(map(int, input().split()))
four = 0
odd = 0
for a in an:
    if a % 2 == 1:
        odd += 1
    elif a % 4 == 0:
        four += 1
print('Yes' if 2*odd-3 <= four or N//2 == four and -(-N//2) == odd else 'No')
