import sys
def fn(n,m):
    kmax = (n-m+1)*(n-m)/2
    k = int(kmax)
    kmin = int(int(n/m)*(int(n/m)-1)/2*(m - n%m) + (int(n/m)+1)*int(n/m)/2*(n%m))   
    print(kmin,k)


if __name__ == '__main__':
    input = sys.stdin.read()
    data = list(map(int, input.split()))
    n = data[0]
    m = data[1]
    fn(n,m)
