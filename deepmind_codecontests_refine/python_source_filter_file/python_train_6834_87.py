n = int(input())
s = '8'*(n//2)+'0'*(n%2)

if len(s)>17:
    print(-1)
else:
    print(s)