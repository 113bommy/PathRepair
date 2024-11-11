import sys,random
input = sys.stdin.readline


def main():
    n = int(input())
    dg = 100000
    xy = []
    for _ in [0]*n:
        x,y = map(int,input().split())
        xy.append(x*dg+y)

    if n == 2:
        x,y = xy[0]//dg,xy[0]%dg
        a,b = xy[1]//dg,xy[1]%dg
        print(((x-a)**2+(y-b)**2)**0.5/2.0)
    else:
        res = -1
        for i in range(n):
            for j in range(i+1,n):
                for k in range(j+1,n):
                    a,b = xy[i]//dg,xy[i]%dg
                    c,d = xy[j]//dg,xy[j]%dg
                    e,f = xy[k]//dg,xy[k]%dg

                    d1 = ((a-c)**2+(b-d)**2)**0.5
                    d2 = ((a-e)**2+(b-f)**2)**0.5
                    d3 = ((e-c)**2+(f-d)**2)**0.5

                    if d1 < d2:
                        d1,d2 = d2,d1
                    if d1 < d3:
                        d1,d3 = d3,d1
                    
                    cos = (d2**2+d3**2-d1**2)/(2.0*d2*d3)
                    if cos > 0 or cos >= -1.0-10**(-8):
                        res = max(res,d1/2.0)
                    else:
                        sin = (1-cos**2)**0.5
    
                        res = max(res,d1*0.5/sin)

                
        print(res)





    

if __name__ == '__main__':
    main()