X = []
count = 0
while (count < 9):
    Y = input()
    Z = [char for char in Y if char!= ' ']
    if Z!= []:
        X.append(Z)
        count += 1 
    
x,y = map(int,input().split())
u = (x-1)%3
v = (y-1)%3
ok = False 
for i in range(3):
    for j in range(3):
        t,s = 3*u + i, 3*v + j 
        if X[t][s] == '.':
            X[t][s] = '!'
            ok = True 
if ok == False:
    for i in range(9):
        for j in range(9):
            if X[i][j] == '.':
                X[i][j] = '!'
cnt = 0
for i in X:
    cnt += 1 
    [u1,u2,u3,u4,u5,u6,u7,u8,u9] = i 
    print(u1 + u2 + u3 + " " + u4 + u5 + u6 + " " + u7 + u8 + u9)
    if cnt == 3 or cnt == 6:
        print("\n")