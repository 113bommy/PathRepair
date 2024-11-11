a=input()
for i in range(int(a),1009):
    s=0
    b=str(i)
    for j in b:
        s+=int(j)
    if s%4==0:
        print(i)
        break
    else:
        continue
