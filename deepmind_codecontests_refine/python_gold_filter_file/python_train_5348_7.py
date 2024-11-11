arr = list(input())
z = 0
if '0' in arr:
    z = arr.index('0')
arr.pop(z)
print(''.join(arr))