from fractions import gcd
def main():
    X = int(input())
    now = [10**10,10**10]
    for i in range(1,int(X**(0.5))+1):
        if X%i==0 and X==(i*(X//i))//gcd(i,X//i):
            if max(i,X//i)<max(now):
                now = [i,X//i]

    print(now[0],now[1])
if __name__ == '__main__':
    main()