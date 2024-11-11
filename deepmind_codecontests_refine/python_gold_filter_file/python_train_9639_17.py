x,y=map(int,input().split())
Ceil=True
while True:
    if Ceil:
        if x>=2:
            if y>=2:
                x-=2; y-=2; Ceil=False
            else:
                print("Hanako"); exit()
        elif x==1:
            if y>=12:
                x-=1; y-=12; Ceil=False
            else:
                print("Hanako"); exit()
        else:
            if y>=22:
                y-=22; Ceil=False
            else:
                print("Hanako"); exit()
    else:
        if y>=22:
            y-=22;Ceil=True
        elif y>=12:
            if x>=1:
                x-=1;y-=12;Ceil=True
            else:
                print("Ciel"); exit()
        elif y>=2:
            if x>=2:
                x-=2;y-=2;Ceil=True
            else:
                print("Ciel"); exit()
        else:
            print("Ciel"); exit()
                
        
        
