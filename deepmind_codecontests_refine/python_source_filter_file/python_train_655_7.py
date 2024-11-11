t = int(input())
for _ in range(t):
    n = int(input())
    a = list(map(int,input().split()))
    above = int((sum(a)/len(a)-sum(a)//len(a))*len(a))
    same = len(a)-above
    print(same*above)
