def sol(l):                     
    pos, neg, z = 0, 0, 0
    for i in l:
        if i > 0:
            pos += 1
        elif i == 0:
            z += 1
        else:
            neg += 1
    
    N = (len(l) - 1) // 2
    if pos > N + 1:
        return 1
    elif neg > N + 1:
        return -1
    else:
        return 0
if __name__ == "__main__":    
    N=int(input())
    A=list(map(int,input().split()))
    print(sol(A))
