_, k = map(int, input().split())
s = list(input())
s[k-1] = s[k-1].upper()
print(''.join(s))