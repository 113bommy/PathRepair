n,k=list(map(int,input().split()))
s  = input()
cl = input().split()

cnt = 0
ssc = []
for c in s:
    if c in cl:
        cnt += 1
    elif cnt > 0:
        ssc.append(cnt)
        cnt = 0
print(sum([(i*(i+1))//2 for i in ssc]))
