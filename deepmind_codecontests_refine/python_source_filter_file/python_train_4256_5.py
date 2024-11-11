n = int(input())
l = list(map(int,input().split()))
l.sort(reverse=True)
print(sum(l[0::2]))