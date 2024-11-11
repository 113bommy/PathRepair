h, w, a, b = map(int, input().split())
ans = "".join(["0"]*a+["1"]*(w-a))
for i in range(b):
    print(ans)
ans = "".join(["1"]*a+["0"]*(w-a))
for i in range(w-b):
    print(ans)