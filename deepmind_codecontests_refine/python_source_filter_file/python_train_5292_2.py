N=int(input())
ab=[[int(i) for i in input().split()] for j in range(N)]
total = sum([sum(row) for row in ab])//2
diff = [row[1] for row in ab if row[0]>row[1]]
if len(diff)==0:
    print(0)
else:
    print(total-diff)
