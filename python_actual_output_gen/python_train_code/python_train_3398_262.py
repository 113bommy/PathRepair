N, R = map(int, input().split())
print(R+100*(10-K) if N<10 else R)