for _ in range(int(input())):
    x,y=map(int,input().split())
    l=input()
    #print(l.count('D'),l.count('U'))
    if x>0 and l.count('R')>=x and y>0 and l.count('U')>=y:
        print("YES")
    elif x<0 and l.count('L')>=abs(x) and y<0 and l.count('D')>=abs(y):
        print("YES")
    elif x>0 and l.count('R')>=abs(x) and y<0 and l.count('D')>=abs(y):
        print("YES")
    elif x<0 and l.count('L')>=abs(x) and y>0 and l.count('U')>=abs(y):
        print("YES")
    else:
        print("NO")