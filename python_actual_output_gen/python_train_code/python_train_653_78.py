N = int(input())
A = list(map(int,input().split()))
A.sort(reverse=True)

print(sum(l[0::2])-sum(l[1::2]))