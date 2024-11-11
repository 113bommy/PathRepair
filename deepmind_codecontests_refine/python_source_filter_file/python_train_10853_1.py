q = [2 ** i for i in range(32)]
for _ in " "*int(input()):
    a=int(input())
    if a==1:
        print("FastestFinger")
    elif a&1 or a==2:print("Ashishgup")
    else:
        if a in q:print("FastestFinger")
        else:
            z=0
            for i in range(2,int((a//2)**0.5)+1):
               if a%i==0:z=1;break
            if z==0:print("FastestFinger")
            else:print("Ashishgup")