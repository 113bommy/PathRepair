a=int(input())
for i in range(a):
        n=int(input())
        for j in range(10*18):
                if n==1:
                    break
                if n%2==0:
                    n=n/2
                elif n%3==0:
                    n=2*n/3
                elif n%5==0:
                    n=4*n/5

        print(j if n==1 else -1)