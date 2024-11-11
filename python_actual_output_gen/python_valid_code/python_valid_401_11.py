def solve(s,n,dragons):
    for d_s,d_b in dragons:
        if s >= d_s:
           s += d_b
        else:
            return 'NO'
    return 'YES'

if __name__ == "__main__":
    s,n = (int(i) for i in input().split())
    dragons = [[int(i) for i in input().split()] for _ in range(n)]
    dragons = sorted(dragons,key=lambda x:x[0])
    print(solve(s,n,dragons))