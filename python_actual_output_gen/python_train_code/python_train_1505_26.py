a = [list(map(int, input().split())) for i in range(3)]
n = int(input())

b = set(int(input() for i in range(n)))

def check():
    for i in range(3):
        if all(a[i][j] in b for j in range(3)):
            return True
        if all(a[j][i] in b for j in range(3)):
            return True
    return all(a[i][i] in b for i in range(3)) or all(a[2-i][i] in b for i in range(3))

print('Yes' if check() else 'No')