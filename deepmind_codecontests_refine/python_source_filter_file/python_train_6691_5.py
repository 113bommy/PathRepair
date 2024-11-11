import sys,math

t=int(input())
for i in range(t):
    n=int(input())
    arr=list(map(int,sys.stdin.readline().strip().split()))
    S=sum(arr)
    if S%n:
        print(-1)
    else:
        out=[]
        for i in range(1,n):
            if arr[i]%(i+1)==0:
                x=arr[i]//(i+1)
                arr[i]-=(x*(i+1))
                arr[0]+=(x*(i+1))
                out.append("{} {} {}\n".format(i+1,1,x))
                # print(arr)
            else:
                y=((i+1)-(arr[i]%(i+1)))
                arr[i]+=y
                arr[0]-=y
                out.append("{} {} {}\n".format(i+1,1,y))
                # print(arr)

                x=arr[i]//(i+1)
                arr[i]-=(x*(i+1))
                arr[0]+=(x*(i+1))      
                out.append("{} {} {}\n".format(i+1,1,x))
                # print(arr)
        for i in range(1,n):
            arr[0]-=(S//n)
            arr[i]+=(S//n)
            out.append("{} {} {}\n".format(1,i+1,S//n))
            # print(arr)

        sys.stdout.write("{}\n".format(len(out)))
        for x in out:
            sys.stdout.write(x)