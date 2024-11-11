#n = int(input())
#n, m = map(int, input().split())
s = input()
#c = list(map(int, input().split()))
l = 8
h = 0
if s[0] == '1' or s[0] == '8':
    h = 1
    l -= 3
if s[1] == 'a' or s[1] == 'h':
    if h == 1:
        l -= 2
    else:
        l -= 3
print(l)