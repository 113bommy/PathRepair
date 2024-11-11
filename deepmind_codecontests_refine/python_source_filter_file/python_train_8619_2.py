import sys
input = sys.stdin.readline

n,Q=map(int,input().split())
b_num = 2**(n-1).bit_length()
mx = 10**9
segl=[mx]*2*b_num 

def update( k, x):
    k += b_num-1
    segl[k] = x
    while k+1:
        k = (k-1)//2
        segl[k] = min(segl[k*2+1],segl[k*2+2])
    
if __name__ == '__main__':
    xs = []
    for i in range(n):
        s,t,x=map(int,input().split())
        xs += [(s-x-0.4,True,x,i), (t-x-0.5,False,x,i)]
    for _ in range(Q):
        xs.append((int(input()),2))
    xs.sort(key=lambda x:x[0])
    for x in xs:
        if x[1]==2:
            print(segl[0] if segl[0]!= mx else -1)
            continue
        update(x[3], x[2] if x[1] else mx)
