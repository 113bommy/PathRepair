a, b , c ,d = map(int, input().split())



mi = min(b,d )
ma = max(a,c)

print(max(0,mi - ma))