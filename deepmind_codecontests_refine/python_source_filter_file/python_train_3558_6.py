n = input().split()
i = 0
ans = []
while int(n[0]) > i:
    str = input()
    if i == 0: x = [None]*int(n[0]); y = [None]*int(n[0])
    x[i] = str.split()
    y[i] = ['0']*int(n[1])
    i+=1
i=0
end = 1
while int(n[0]) > i:
    for j, item in enumerate(x[i]):
       if item == 0:
           continue
       if j+1<len(x[i]) and i+1<int(n[0]):
           if x[i+1][j+1]=='1' and x[i][j+1]=='1' and x[i+1][j]=='1':
               y[i+1][j+1] = y[i][j+1] = y[i+1][j] = y[i][j] = '1'
               ans.append([i,j])
    i+=1
i=0
while int(n[0]) > i:
    for j, item in enumerate(x[i]):
        if item != y[i][j]:
            print("-1")
            end = 0
            break
    if not end: break
    i+=1
if end:
    if not ans:
        print(0)
    else:
        print(len(ans))
        for item in ans:
            print("{one} {two}".format(one=int(item[0])+1,two=int(item[1])+1))