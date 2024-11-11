n,r = map(int, input().split())
print((100*(10-n)+r) if n<10 else r)