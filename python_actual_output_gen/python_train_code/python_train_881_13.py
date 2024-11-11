from sys import stdin,stdout
for _ in range(int(stdin.readline())):
    # n=int(stdin.readline());
    cns_va,cns1,va,sm=list(map(int,stdin.readline().split()))
    # a=sorted(map(int,stdin.readline().split()))
    needed=sm//va
    summade=needed*cns_va
    diff=sm-summade
    if cns1>=diff:print('YES')
    else:print('NO')