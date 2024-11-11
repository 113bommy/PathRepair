import sys
input = sys.stdin.readline

for _ in range(int(input())):
    a,b,c = map(int,input().split())
    monster = [[0,0] for _ in range(c)]
    tmp1 = list(map(int,input().split()))
    tmp2 = list(map(int,input().split()))
    for i in range(c):
        monster[i][0] = tmp1[i]
        monster[i][1] = tmp2[i]
    monster = sorted(monster, key = lambda x:(x[0], x[1]))
    for power, health in monster:
        tmp = (health//a if health%a == 0 else health//a+1)
        b -= power*tmp
    if b >= -monster[-1][0]:
        print("YES")
    else:
        print("NO")