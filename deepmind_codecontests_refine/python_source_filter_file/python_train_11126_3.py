from operator import itemgetter
n = int(input())
rs = [list(map(int(),input().split())) for i in range(n)]
rs = sorted(rs,key=itemgetter(0))
print(' '.join(map(str, sorted(rs, key=itemgetter(1),reverse=True)[0])))