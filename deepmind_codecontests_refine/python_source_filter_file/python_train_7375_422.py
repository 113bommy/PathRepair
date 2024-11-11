n=int(input())
print(sum(sorted(map(int,input().split()))[-1-n:-1]))