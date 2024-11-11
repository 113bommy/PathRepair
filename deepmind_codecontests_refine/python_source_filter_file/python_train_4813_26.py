t=int(input())

for _ in range(t):
    a, b, c=map(int, input().split())

    ans=[0,0,0]
    m=9999999999
    for i in range(1, 10001):
        for j in range(i, 10001, i):
            for k in range(j, 10001, j):
                if m>abs(a-i)+abs(b-j)+abs(c-k):
                    m=abs(a-i)+abs(b-j)+abs(c-k)
                    ans=[i, j, k]
    
    print(m)
    print(*ans)