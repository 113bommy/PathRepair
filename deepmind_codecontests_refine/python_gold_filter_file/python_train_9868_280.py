n,r = map(int, input().split())
print(r if 10<=n else (r+100*(10-n)))