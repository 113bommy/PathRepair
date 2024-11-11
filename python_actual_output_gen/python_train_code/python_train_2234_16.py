#imgur.com/Pkt7iIf.png

#n, m = map(int, input().split())
#n = int(input())
#d = list(map(int, input().split()))

n = int(input())
s = input()

print(s[:-10])
m = s[:-10].count('8')
if m <= (n-11)//2:
    print('NO')
else:
    print('YES')