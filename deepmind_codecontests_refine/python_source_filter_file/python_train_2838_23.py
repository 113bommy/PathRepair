for i in range(int(input())):
	
    t=list(map(int,input().split()))
    t.sort()
    if t[1]!=t[2]:
        print('NO')
    else:
        print('YES')
        print(t[2],t[0],t[0]-1)
