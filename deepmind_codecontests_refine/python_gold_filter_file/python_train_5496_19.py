M = int(input())

lis = [0] * 10
able =0

for i in range(M):

    d,c = map(int,input().split())

    lis[d] += c

    able += d * c
    
print ( sum(lis)-1 + (able-1) // 9 )
