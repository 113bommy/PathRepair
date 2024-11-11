a=int(input())
for i in range(0,a):
    b=input()
    if b.find("po",len(b)-3)>-1:
        print("FILIPINO")
    elif b.find("mnida",len(b)-6)>-1:
        print("KOREAN")
    else:
        print("JAPANESE")
    
    
