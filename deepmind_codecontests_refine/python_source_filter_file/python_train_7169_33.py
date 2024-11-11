# -*- coding:utf-8 -*-

def main():
    for i in range(int(input())):
        x1,y1,x2,y2,x3,y3,x4,y4=map(float,input().split())

        if abs((x2-x1)*(y4-y3)-(x4-x3)*(y2-y1))==0:
            print("YES")
        else:
            print("NO")
    
        
if __name__ == '__main__':
    main()