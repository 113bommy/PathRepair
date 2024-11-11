n = int(input())
a = list(map(int, input().split()))
if len(a) == 1:
    print(0)
else:
    print(len(a)-a.count(min(a))-a.count(max(a)))
