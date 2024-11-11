n=int(input())
a=sorted(list(map(int,input().split())))
a_mid=a[n::2]
print(sum(a_mid))
