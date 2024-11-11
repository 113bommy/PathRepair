SS = int(input())

ans = set(list(map(int,input().split()))[1:])
for s in range(SS-1):
    ans = ans.intersection(set(list(map(int,input().split()))[1:]))
    
for a in ans:
    print(a,end=' ')