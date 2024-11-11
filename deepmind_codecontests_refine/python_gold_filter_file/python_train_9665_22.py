n=int(input())
ans=set()
for i in range(n):
    ans^=set([input()])
print(len(ans))