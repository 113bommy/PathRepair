N, K =map(int, input().split())
st = input()
print(st[:N-1] + st[N-1].lower()+st[N+1:])