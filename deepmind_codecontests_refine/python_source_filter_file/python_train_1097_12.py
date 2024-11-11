n=int(input())
vectors=[]
for i in range(n):
    vectors.append([int(x) for x in input().split()])
xyz=[0,0,0]
for o in range(3):
    for i in range(n):
        xyz[o]+=vectors[i][o]
if xyz[0]==0 and xyz[1]==0 and xyz[2]: print('YES')
else: print('NO')