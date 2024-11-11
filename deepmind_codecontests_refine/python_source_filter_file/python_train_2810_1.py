ls_g=[]
ls_y=[]
ls_m=[]
ls_d=[]
cnt = -1
while True:
    try:
        ls=input().split()
        ls_g.append(ls[0])
        ls_y.append(int(ls[1]))
        ls_m.append(int(ls[2]))
        ls_d.append(int(ls[3]))
        cnt += 1
    except:
        break;

for _ in range(cnt):
    if ls_y[_]>31:
        ls_g[_]="?"
        ls_y[_]-=30
    elif ls_y[_]==31 and ls_m[_]>=5:
        ls_g[_]="?"
        ls_y[_]-=30
for i in range(cnt):
    print(ls_g[i]+" "+str(ls_y[i])+" "+str(ls_m[i])+" "+str(ls_d[i]))        

