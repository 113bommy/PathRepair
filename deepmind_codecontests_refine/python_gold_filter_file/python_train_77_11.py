N=int(input())
S=[input() for _ in range(N)]
for k in ['AC','WA','TLE','RE']:
    print('{0} x {1}'.format(k,S.count(k)))