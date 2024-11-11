lst=list(map(int, input().split()))
if (sum(lst)%5) and (not sum(lst)==0):
    print(-1)
else:
    print(sum(lst)//5)
