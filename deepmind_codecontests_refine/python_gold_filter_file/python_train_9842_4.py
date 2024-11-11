d,h,V2,e=map(float,input().split())
pi=3.14159292
V1=pi*((d/2)**2)*h
V3=pi*((d/2)**2)*e
if V3>V2 or V1/(V2-V3)>10000: print('NO')
else:
    print('YES')
    print(V1/(V2-V3))