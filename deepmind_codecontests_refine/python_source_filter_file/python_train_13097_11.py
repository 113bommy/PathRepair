n = int(input())
abc = [list(map(int, input().split())) for i in range(N)]
a,b,c=abc[0][0],abc[0][1],abc[0][2]
for i in range(1,n):
    a,b,c = abc[i][0]+max(b,c),abc[i][1]+max(a,c),abc[i][2]+max(a,b)
print(max(a,b,c))