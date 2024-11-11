import io,os
input = io.BytesIO(os.read(0, os.fstat(0).st_size)).readline

def main(t):


    n = int(input())
    s = input()

    for i in range(n//2):
        if s[i]==ord('0'):
            print(i+1,n,i+2,n)
            return 
    for i in range(n//2,n):
        if s[i]==ord('0'):
            print(1,i,1,i+1)
            return 


    print(1,n//2,1,n//2*2)























T = int(input())
t = 1
while t<=T:
    main(t)
    t += 1
