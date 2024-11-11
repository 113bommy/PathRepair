n = int(input())
s = '8'*(n//2)+'4'*(n%2)

if len(s)>18:
    print(-1)
else:
    print(s)