inp = int(input())
l = list(map(int,input().split()))
p = sorted(l)
if len(l) > 1:
    if p[0] == p[1]:
        print("Still Rozdil")
    else:
        print(l.index(min(l))+1)
else:
    print(1)