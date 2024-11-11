import io
import os
input=io.BytesIO(os.read(0,os.fstat(0).st_size)).readline
def main():
    for t in range(int(input())):
        if t>=1:
            input()
        n, m = map(int, input().split())
        a=[]
        for i in range(m):
            x, y = map(int, input().split())
            a.append([x,i+1,"a"])
            a.append([y,i+1,"b",x])
        a.sort(reverse=True,key= lambda x:x[0])
        b=set()
        l=su=ma=i=0
        while i<2*m and n-l>0:
            if a[i][2]=="a":
                su+=a[i][0]
                b.add(a[i][1])
                l += 1
            else:
                if a[i][1] in b:
                    if ma<su+(n-l)*a[i][0]:
                        ma=su+(n-l)*a[i][0]
                else:
                    if ma<su+(n-l-1)*a[i][0]+a[i][3]:
                        ma=su+(n-l-1)*a[i][0]+a[i][3]
            i+=1
        if ma<su:
            ma=su
        print(ma)
if __name__=="__main__":
    main()