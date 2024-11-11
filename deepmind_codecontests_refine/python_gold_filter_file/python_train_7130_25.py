n = int(input())
A = {'ABSINTH', 'BEER', 'BRANDY', 'CHAMPAGNE', 'GIN', 'RUM', 'SAKE', 'TEQUILA', 'VODKA', 'WHISKEY', 'WINE'}
B = {'0','1','2','3','4','5','6','7','8','9'}
k = 0
for i in range(n):
    s = input()
    if s[0] in B:    # it is a number
        v = int(s)
        if v < 18:
            k += 1
    else:      # it is a string
        if s in A:
            k += 1
print(k)