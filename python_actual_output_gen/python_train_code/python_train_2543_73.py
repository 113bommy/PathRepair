l, r, d = map(int, input().split())

ans = int(r/d)-int(l-1/d)
print(ans)