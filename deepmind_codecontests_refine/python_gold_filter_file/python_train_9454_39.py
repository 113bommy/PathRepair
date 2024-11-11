import sys
def main():
    input = sys.stdin.readline
    N=int(input())
    k=1
    while k <= N*2:
        if k*(k-1)==2*N: break
        k+=1
    else:
        print('No')
        return
    print('Yes')
    print(k)
    ans=[[] for _ in range(k)]
    v=1
    for i in range(k):
        for j in range(i+1,k):
            ans[i].append(v)
            ans[j].append(v)
            v+=1
    for a in ans:
        print(len(a),*a)

if __name__ == '__main__':
    main()