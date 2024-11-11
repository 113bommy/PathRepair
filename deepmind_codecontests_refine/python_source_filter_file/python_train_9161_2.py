def invNum(d,A):
    if d < 0 or not A: return 0
    cnt = 0
    L = []
    R = []
    for ai in A:
        if ai < 2**d:
            L.append(ai)
            cnt += len(R)
        else:
            R.append(ai-2**d)
    return cnt + invNum(d-1,L) + invNum(d-1,R)
 
if __name__=='__main__':
    n = int(input()) 
    print(invNum(29,list(map(int,input().split()))))