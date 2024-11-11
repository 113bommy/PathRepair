n,h,a,b,k=[int(i) for i in input().split()]
for i in range(k):
        t1,f1,t2,f2=[int(i) for i in input().split()]
        if(t1!=t2):
                if (f1<=b and f1>=a):
                        z=0
                        curr=f1
                elif (f2<=b and f2>=a):
                        z=abs(f1-f2)
                        curr=f2
                else:
                        if (abs(a-f1)>abs(b-f1)):#ac to  f1 is near to any a and b
                                z=abs(b-f1)
                                curr=b
                        else:
                                z=abs(a-f1)
                                curr=a
                z=z+abs(t2-t1)+abs(curr-f2)
                print(z)
        else:
                print(abs(f1-f2))
