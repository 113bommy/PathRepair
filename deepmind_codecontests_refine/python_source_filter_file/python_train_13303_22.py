T1, T2=(int(i) for i in input().split())
A1, A2=(int(i) for i in input().split())
B1, B2=(int(i) for i in input().split())

if T1*A1+T2*A2==T1*B1+T2*B2:
    print("infinity")
elif ((A1>B1) & (T1*A1+T2*A2-(T1*B1+T2*B2)>0)) or ((A1<B1) & (T1*A1+T2*A2-(T1*B1+T2*B2)<0)):
    print(0)
else:
    d=T1*A1+T2*A2-(T1*B1+T2*B2)#T1+T2だけ走った後離れている距離
    ss=0
    if abs(T1*(A1-B1))%d==0:
        ss=1
        
    print(abs(T1*(A1-B1))//d*2-ss+1)