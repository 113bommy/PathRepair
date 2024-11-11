def main():
    import sys
    input = sys.stdin.readline
    
    #N = int(input())
    #A = list(map(int,input().split()))
    N = 2*10**5
    A = [i for i in range(1,N+1)]
    
    from collections import deque
    que = deque()
    for i in range(N):
        if i%2==0:
            que.append(A[i])
        else:
            que.appendleft(A[i])
    #print(list(que))
    if N%2==0:
        print(*list(que))
    else:
        print(*((list(que))[::-1]))
    
main()