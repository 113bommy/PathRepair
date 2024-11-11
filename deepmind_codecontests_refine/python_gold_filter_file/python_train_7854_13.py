sorted_arr = []
actual = []
early = []
for _ in range(int(input())):
    a,b = list(map(int,input().split()))
    actual.append(a)
    early.append(b)

sorted_arr = [[x,y] for x,y in sorted(zip(actual,early))]
ans =0
for x,y in sorted_arr:
    if(y>=ans):
        ans=y
    else:
        ans=x
print(ans)