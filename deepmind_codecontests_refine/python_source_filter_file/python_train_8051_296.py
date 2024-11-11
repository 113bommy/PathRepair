k = int(input())
a = sum(i/100 for i in map(int,input().split()))
print(round(a/k,5))